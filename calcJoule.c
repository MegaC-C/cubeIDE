#define JOULE_TO_BIT 98563728473	// depends on hardware components and time to fill the buffer
uint16_t adcBuffer[2];
uint16_t adcMosfet = 0;
uint16_t adcSupply = 0;
uint64_t rawJoule = 0;		// measured Joule converted to raw BIT value 
uint64_t maxJoule = 0;		// selected Joule value converted to raw BIT value
int8_t setJoule = 0; 		// energy in Joule, select value between 0 and 99


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



//IRQ EXTIBUttton1()
{
	++setJoule;
	if (setJoule >= 100) setJoule = 0;
	maxJoule = setJoule * JOULE_TO_BIT;
	displayNum (setJoule);
}

//IRQ EXTIBUttton2()
{
	--setJoule;
	if (setJoule <= -1) setJoule = 99;
	maxJoule = setJoule * JOULE_TO_BIT;
	displayNum (setJoule);
}

//IRQ with test which PIN fired the interrupt
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_9) // If The INT Source Is EXTI Line9 (A9 Pin)
    {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); // Toggle The Output (LED) Pin
    }
}