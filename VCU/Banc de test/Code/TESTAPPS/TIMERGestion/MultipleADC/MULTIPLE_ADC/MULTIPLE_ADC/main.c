#include <atmel_start.h>

// static struct timer_task TIMER_0_task1;
// static struct timer_task TIMER_0_task2;
// static struct timer_task TIMER_0_task3;

volatile bool adc0_flag = false;
volatile bool adc1_flag = false;

uint8_t       adc0_buffer[2];
uint16_t      adc0_length = 2;
uint16_t      adc0_value  = 0;

uint8_t       adc1_buffer[2];
uint16_t      adc1_length = 2;
uint16_t      adc1_value  = 0;


// static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
// {
// 	gpio_set_pin_level(LED0,true);
// };
// 
// static void TIMER_0_task2_cb(const struct timer_task *const timer_task)
// {
// 	gpio_set_pin_level(LED0,false);
// };
// 
// static void TIMER_0_task3_cb(const struct timer_task *const timer_task)
// {
// };

static void convert_cb_ADC_0(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
	adc0_flag = true;
}

static void convert_cb_ADC_1(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
	adc1_flag = true;
}


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
// 	TIMER_0_task1.interval = 4;
// 	TIMER_0_task1.cb       = TIMER_0_task1_cb;
// 	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
// 	
// 	TIMER_0_task2.interval = 9;
// 	TIMER_0_task2.cb       = TIMER_0_task2_cb;
// 	TIMER_0_task2.mode     = TIMER_TASK_REPEAT;
// 	
// 	TIMER_0_task3.interval = 25;
// 	TIMER_0_task3.cb       = TIMER_0_task3_cb;
// 	TIMER_0_task3.mode     = TIMER_TASK_REPEAT;
// 	
// 	timer_add_task(&TIMER_0, &TIMER_0_task1);
// 	timer_add_task(&TIMER_0, &TIMER_0_task2);
// 	timer_add_task(&TIMER_0, &TIMER_0_task3);
// 	timer_start(&TIMER_0	/* Replace with your application code */
	while (1) {

	}
}
