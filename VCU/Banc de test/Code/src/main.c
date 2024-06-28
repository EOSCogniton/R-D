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




// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************


char buffer[50];
int testodess = 10;
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    // Envoyer un message initial
    //strcpy((char *)buffer, "Hi You \r\n");
    sprintf((char *)buffer, "New value: %d\r\n", testodess);
    SERCOM4_USART_Write((void*)buffer, strlen((char*)buffer));

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( ); 
        testodess = testodess + 1;
        sprintf((char *)buffer, "New value: %d\r\n", testodess);
        SERCOM4_USART_Write((void*)buffer, strlen((char*)buffer));

        

    }
      /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

