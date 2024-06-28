/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <stdio.h>                      // Pour sprintf
#include <string.h>


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
char buffer[50];

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    uint16_t adcValue = 0x1000;
    ADC0_ConversionStart();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        
        /* Wait for ADC conversion to complete */
        if (!ADC0_ConversionStatusGet())
        {
            adcValue = ADC0_ConversionResultGet();
            sprintf((char *)buffer, "%u\r\n", adcValue);
            SERCOM4_USART_Write((void*)buffer, strlen((char*)buffer));
            ADC0_ConversionStart();
        }       
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

