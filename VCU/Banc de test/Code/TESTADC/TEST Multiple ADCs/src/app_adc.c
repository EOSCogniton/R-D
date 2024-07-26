/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_adc.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_adc.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_ADC_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_ADC_DATA app_adcData;
QueueHandle_t ADC_Queue_Handle;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_ADC_Initialize ( void )

  Remarks:
    See prototype in app_adc.h.
 */

void APP_ADC_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_adcData.state = APP_ADC_STATE_INIT;
    
    app_adcData.adc_channel = 2;    
    ADC0_Enable();
    ADC0_ChannelSelect(ADC_POSINPUT_AIN2,ADC_NEGINPUT_GND);
    
    app_adcData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0); 
    ADC_Queue_Handle = xQueueCreate( 5, sizeof( uint8_t ) );

    


    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_ADC_Tasks ( void )

  Remarks:
    See prototype in app_adc.h.
 */

void APP_ADC_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_adcData.state )
    {
        /* Application's initial state. */
        case APP_ADC_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                app_adcData.state = APP_ADC_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_ADC_STATE_SERVICE_TASKS:
        {
            if (xQueueReceive(ADC_Queue_Handle,&app_adcData.queue_item,0) == pdTRUE) {
                if (app_adcData.adc_channel == 2) {
                    app_adcData.adc_channel = 3;  
                    ADC0_ChannelSelect(ADC_POSINPUT_AIN3,ADC_NEGINPUT_GND);
                }
                else {
                    app_adcData.adc_channel = 2;  
                    ADC0_ChannelSelect(ADC_POSINPUT_AIN2,ADC_NEGINPUT_GND);
                }
            };
            ADC0_ConversionStart();
            vTaskDelay(10U / portTICK_PERIOD_MS);
            app_adcData.adc_value = ADC0_ConversionResultGet();
            sprintf(app_adcData.buffer_USART,"ADC%d : %d\r\n",app_adcData.adc_channel,app_adcData.adc_value);
            DRV_USART_WriteBuffer(app_adcData.usartHandle, app_adcData.buffer_USART, ADC_WRITE_BUFFER_SIZE);
            vTaskDelay(1000U / portTICK_PERIOD_MS);
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
