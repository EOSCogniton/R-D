/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

#include <hpl_adc_base.h>
#include <hpl_adc_base.h>
#include <hpl_rtc_base.h>

/* The channel amount for ADC */
#define ADC_0_CH_AMOUNT 1

/* The buffer size for ADC */
#define ADC_0_BUFFER_SIZE 16

/* The maximal channel number of enabled channels */
#define ADC_0_CH_MAX 0

/* The channel amount for ADC */
#define ADC_1_CH_AMOUNT 1

/* The buffer size for ADC */
#define ADC_1_BUFFER_SIZE 16

/* The maximal channel number of enabled channels */
#define ADC_1_CH_MAX 0

struct adc_async_descriptor         ADC_0;
struct adc_async_channel_descriptor ADC_0_ch[ADC_0_CH_AMOUNT];
struct adc_async_descriptor         ADC_1;
struct adc_async_channel_descriptor ADC_1_ch[ADC_1_CH_AMOUNT];
struct timer_descriptor             TIMER_0;

static uint8_t ADC_0_buffer[ADC_0_BUFFER_SIZE];
static uint8_t ADC_0_map[ADC_0_CH_MAX + 1];
static uint8_t ADC_1_buffer[ADC_1_BUFFER_SIZE];
static uint8_t ADC_1_map[ADC_1_CH_MAX + 1];

struct usart_sync_descriptor TARGET_IO;

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
void ADC_0_init(void)
{
	hri_mclk_set_APBCMASK_ADC0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC0_GCLK_ID, CONF_GCLK_ADC0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	adc_async_init(&ADC_0, ADC0, ADC_0_map, ADC_0_CH_MAX, ADC_0_CH_AMOUNT, &ADC_0_ch[0], _adc_get_adc_async());
	adc_async_register_channel_buffer(&ADC_0, 0, ADC_0_buffer, ADC_0_BUFFER_SIZE);

	// Disable digital pin circuitry
	gpio_set_pin_direction(PB08, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(PB08, PINMUX_PB08B_ADC0_AIN2);

	// Disable digital pin circuitry
	gpio_set_pin_direction(PB09, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(PB09, PINMUX_PB09B_ADC0_AIN3);
}

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
void ADC_1_init(void)
{
	hri_mclk_set_APBCMASK_ADC1_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC1_GCLK_ID, CONF_GCLK_ADC1_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	adc_async_init(&ADC_1, ADC1, ADC_1_map, ADC_1_CH_MAX, ADC_1_CH_AMOUNT, &ADC_1_ch[0], _adc_get_adc_async());
	adc_async_register_channel_buffer(&ADC_1, 0, ADC_1_buffer, ADC_1_BUFFER_SIZE);

	// Disable digital pin circuitry
	gpio_set_pin_direction(PA08, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(PA08, PINMUX_PA08B_ADC1_AIN10);
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	hri_mclk_set_APBAMASK_RTC_bit(MCLK);
	timer_init(&TIMER_0, RTC, _rtc_get_timer());
}

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(PB10, PINMUX_PB10D_SERCOM4_PAD2);

	gpio_set_pin_function(PB11, PINMUX_PB11D_SERCOM4_PAD3);
}

void TARGET_IO_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_SLOW, CONF_GCLK_SERCOM4_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM4_bit(MCLK);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	usart_sync_init(&TARGET_IO, SERCOM4, (void *)NULL);
	TARGET_IO_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA15

	gpio_set_pin_level(LED0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);

	ADC_0_init();
	ADC_1_init();

	TIMER_0_init();

	TARGET_IO_init();
}
