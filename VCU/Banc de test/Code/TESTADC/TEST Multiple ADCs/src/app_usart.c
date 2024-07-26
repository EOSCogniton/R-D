/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_usart.c

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

#include "app_usart.h"

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
    This structure should be initialized by the APP_USART_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_USART_DATA app_usartData;
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
    void APP_USART_Initialize ( void )

  Remarks:
    See prototype in app_usart.h.
 */

void APP_USART_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_usartData.state = APP_USART_STATE_INIT;
    app_usartData.queue_item = 0;
    app_usartData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0); 

}

/******************************************************************************
  Function:
    void APP_USART_Tasks ( void )

  Remarks:
    See prototype in app_usart.h.
 */

void APP_USART_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_usartData.state )
    {
        /* Application's initial state. */
        case APP_USART_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                app_usartData.state = APP_USART_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_USART_STATE_SERVICE_TASKS:
        {
            if (DRV_USART_ReadBuffer(app_usartData.usartHandle, &app_usartData.buffer, 8) == true)
                {
                if (strcmp(app_usartData.buffer,"switch\r\n")) {}
                else {
                    xQueueSend(ADC_Queue_Handle,&app_usartData.queue_item,10);
                }
            }
        }




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
