// enable Continious Conversion Mode and DMA continous request
// MX_DMA_Init(); must be called before MX_ADC1_Init(); 

#define ADC_BUF_LEN 20

void processData(){
	for (uint8_t n = 0; n < (ADC_BUF_LEN/2) - 1; n += 2){
		adcMosfet[n/2] = adc_buf_ptr[n];
		adcVoltage[n/2] = adc_buf_ptr[n + 1];
}

uint16_t adcMosfet[ADC_BUF_LEN/2];
uint16_t adcVoltage[ADC_BUF_LEN/2];
uint16_t adc_buf[ADC_BUF_LEN];
static volatile uint16_t *adc_buf_ptr;
uint8_t dataReadyFlag;


//main
HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, ADC_BUF_LEN);

//while (1)
if (dataReadyFlag == 1) processData();



void HAL_ADC_ConvHalfCpltCallback(...){
	adc_buf_ptr = &adc_buf[0];
	dataReadyFlag = 1;
}

void HAL_ADC_ConvCpltCallback(...){
	adc_buf_ptr = &adc_buf[ADC_BUF_LEN/2];
	dataReadyFlag = 1;	
}