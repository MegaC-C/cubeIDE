/* 
---JOULE_TO_BIT is derived from three parts--- 
1.)time of ADC_DMA to fill the Buffer:
	Xµs, determined by GPIO SET/RESET between HAL_ADC_ConvCpltCallback
2.)conversion factor of SupplyVoltage:
	V = (2kOhm+8kOhm)/2kOhm * 3.3V * (1 / 2e16) * adcSupply
	V = voltage divider * reference voltage * 1 divided by max bit value of adcSupply * adcSupply
3.)conversion factor of Ampere through Mosfets:
	A = (1 / 120e-6 Ohm) * 3.3V * (1 / 2e16) * adcMosfet 
	A = 1 divided by resistance of four IRL40SC228 Mosfets in parallel (120µOhm) * reference voltage * 1 divided by max bit value of adcMosfet * adcMosfet
Combined:
	J = V*A*s = 
*/
#define JOULE_TO_BIT 98563728473	// depends on hardware components and time to fill the buffer
uint16_t adcBuffer[2];
uint16_t adcMosfet = 0;
uint16_t adcSupply = 0;
uint64_t rawJoule = 0;		// measured Joule converted to raw BIT value 
uint64_t maxJoule = 0;		// selected Joule value converted to raw BIT value
int8_t setJoule = 0; 		// energy in Joule, select value between 0 and 99
uint8_t startFlag = 0;
uint8_t upFlag = 0;
uint8_t downFlag = 0;
uint8_t bufferHalfFlag = 0;
uint8_t bufferFullFlag = 0;


if (bufferHalfFlag == 1)
{
	bufferHalfFlag = 0;
	adcMosfet = adcBuffer[0];
}

if (bufferFullFlag == 1)
{
	bufferFullFlag = 0;
	adcSupply = adcBuffer[1];
	rawJoule += (adcMosfet * adcSupply);
	if (rawJoule >= maxJoule) ...turnMosfetsOff()...
}




void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){
	bufferHalfFlag = 1;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	bufferFullFlag = 1;
}



//IRQ with test which PIN fired the interrupt
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == START_Pin)
	{
		startFlag = 1;
		HAL_TIM_Base_Start_IT(&htim14); // Start timer with interrupt for debounce
	}
	else if(GPIO_Pin == UP_Pin) 
    {
		upFlag = 1;
		HAL_TIM_Base_Start_IT(&htim14); // Start timer with interrupt for debounce
    }
	else if (GPIO_Pin == DOWN_Pin)
	{
		downFlag = 1;
		HAL_TIM_Base_Start_IT(&htim14); // Start timer with interrupt for debounce
	}
}

// Callback: timer has rolled over (TIM14 with overflow set to 50ms for button debounce)
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Stop_IT(&htim14); // Stop timer with interrupt
	// Check which version of the timer triggered this callback and service it 
	if (htim == &htim14 )
	{
		if (startFlag == 1)
		{
			startFlag = 0;
			if (setJoule != 0)
			{
				// ..set mosfet, start adc_dma, calculate joule, reset mosfet
			}				
		}
		else if (upFlag == 1)
		{
			upFlag = 0;
			++setJoule;
			if (setJoule >= 100) setJoule = 0;
			maxJoule = setJoule * JOULE_TO_BIT;
			displayNum (setJoule);			
		}
		else if (downFlag == 1)
		{
			downFlag = 0;
			--setJoule;
			if (setJoule <= -1) setJoule = 99;
			maxJoule = setJoule * JOULE_TO_BIT;
			displayNum (setJoule);			
		}
	}
}
