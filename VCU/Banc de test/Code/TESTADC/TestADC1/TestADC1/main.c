#include <atmel_start.h>

uint16_t adc_value  = 0;
volatile bool adc_flag = false;
static uint8_t adc_Channel = 3;
uint8_t adc_buffer[2];
uint16_t adc_length = 2;

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	adc_sync_enable_channel(&ADC_0, adc_Channel);
	adc_sync_convert(&ADC_0);
	/* Replace with your application code */
	while (1) {
		printf("Start of loop.\r\n");
		adc_flag = _adc_sync_is_channel_conversion_done(&ADC_0,adc_Channel);
		if (adc_flag){
			adc_sync_read_channel(&ADC_0,adc_Channel,adc_buffer,adc_length);
			adc_flag = false;
		} 
		else
		{printf("End of loop, conversion not finished.\r\n");}
	}
}
