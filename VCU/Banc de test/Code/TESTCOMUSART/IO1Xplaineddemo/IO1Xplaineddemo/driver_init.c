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

struct adc_sync_descriptor IO1_LIGHT_SENS;

struct i2c_m_sync_desc I2C;

struct usart_sync_descriptor EDBG_COM;

void IO1_LIGHT_SENS_PORT_init(void)
{

	// Disable digital pin circuitry
	gpio_set_pin_direction(IO1_LIGHTSENSOR, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(IO1_LIGHTSENSOR, PINMUX_PB09B_ADC0_AIN3);
}

void IO1_LIGHT_SENS_CLOCK_init(void)
{
	hri_mclk_set_APBCMASK_ADC0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC0_GCLK_ID, CONF_GCLK_ADC0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void IO1_LIGHT_SENS_init(void)
{
	IO1_LIGHT_SENS_CLOCK_init();
	IO1_LIGHT_SENS_PORT_init();
	adc_sync_init(&IO1_LIGHT_SENS, ADC0, _adc_get_adc_sync());
}

void I2C_PORT_init(void)
{

	gpio_set_pin_pull_mode(IO1_TWI_SDA,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(IO1_TWI_SDA, PINMUX_PA12C_SERCOM2_PAD0);

	gpio_set_pin_pull_mode(IO1_TWI_SCL,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(IO1_TWI_SCL, PINMUX_PA13C_SERCOM2_PAD1);
}

void I2C_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM2_GCLK_ID_CORE, CONF_GCLK_SERCOM2_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM2_GCLK_ID_SLOW, CONF_GCLK_SERCOM2_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM2_bit(MCLK);
}

void I2C_init(void)
{
	I2C_CLOCK_init();
	i2c_m_sync_init(&I2C, SERCOM2);
	I2C_PORT_init();
}

void EDBG_COM_PORT_init(void)
{

	gpio_set_pin_function(EDBG_COM_TX, PINMUX_PB10D_SERCOM4_PAD2);

	gpio_set_pin_function(EDBG_COM_RX, PINMUX_PB11D_SERCOM4_PAD3);
}

void EDBG_COM_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_SLOW, CONF_GCLK_SERCOM4_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM4_bit(MCLK);
}

void EDBG_COM_init(void)
{
	EDBG_COM_CLOCK_init();
	usart_sync_init(&EDBG_COM, SERCOM4, (void *)NULL);
	EDBG_COM_PORT_init();
}

void system_init(void)
{
	init_mcu();

	IO1_LIGHT_SENS_init();

	I2C_init();

	EDBG_COM_init();
}
