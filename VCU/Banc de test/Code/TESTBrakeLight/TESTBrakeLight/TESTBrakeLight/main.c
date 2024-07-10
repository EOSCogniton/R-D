#include <atmel_start.h>

uint8_t       adc_buffer[2];
uint16_t      adc_length = 2;
uint16_t      adc_value  = 0;
uint16_t	  Brake_Threshold = 1000;
volatile bool adc_flag   = false;

static void convert_cb_ADC_0(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
	adc_flag = true;
}

int main(void)
{
	atmel_start_init();


	adc_async_register_callback(&ADC_0, 0, ADC_ASYNC_CONVERT_CB, convert_cb_ADC_0);
	adc_async_enable_channel(&ADC_0, 0);
	/* Start timer */
	timer_start(&TIMER_0);

	while (1) {
		if (adc_flag) {
			adc_async_read_channel(&ADC_0, 0, adc_buffer, adc_length);
			adc_value = adc_buffer[1] << 8 | adc_buffer[0];
			adc_value = adc_value * 5000 / 4096;
			if(adc_value>Brake_Threshold){
				gpio_set_pin_level(LED0,false);
			}
			else{gpio_set_pin_level(LED0,true);}
			printf("ADC Value: %d\r\n", adc_value);
			adc_flag = false;
		}
	}
}
