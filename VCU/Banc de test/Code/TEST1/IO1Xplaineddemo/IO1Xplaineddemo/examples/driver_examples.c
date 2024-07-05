/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using IO1_LIGHT_SENS to generate waveform.
 */
void IO1_LIGHT_SENS_example(void)
{
	uint8_t buffer[2];

	adc_sync_enable_channel(&IO1_LIGHT_SENS, 0);

	while (1) {
		adc_sync_read_channel(&IO1_LIGHT_SENS, 0, buffer, 2);
	}
}

void I2C_example(void)
{
	struct io_descriptor *I2C_io;

	i2c_m_sync_get_io_descriptor(&I2C, &I2C_io);
	i2c_m_sync_enable(&I2C);
	i2c_m_sync_set_slaveaddr(&I2C, 0x12, I2C_M_SEVEN);
	io_write(I2C_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using EDBG_COM to write "Hello World" using the IO abstraction.
 */
void EDBG_COM_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&EDBG_COM, &io);
	usart_sync_enable(&EDBG_COM);

	io_write(io, (uint8_t *)"Hello World!", 12);
}
