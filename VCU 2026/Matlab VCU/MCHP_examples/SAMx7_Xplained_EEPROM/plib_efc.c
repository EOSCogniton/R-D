/*******************************************************************************
Interface definition of EFC PLIB.
Modified for use with Simulink

Company:
Microchip Technology Inc.

File Name:
plib_efc.h

Summary:
Interface definition of EFC Plib.

Description:
This file defines the interface for the EFC Plib.
It allows user to Program, Erase and lock the on-chip FLASH memory.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include <xc.h>
//#include <stddef.h>              // Defines NULL
//#include <stdbool.h>             // Defines true
//#include <stdlib.h>              // Defines EXIT_FAILURE
//#include <string.h>
//#include <stdint.h>
//#include "device.h"
//#include "plib_efc.h"
//#include "interrupts.h"



//const uint32_t EEPROM[128] __attribute__((section("nvmsec"),aligned(32) )); /* Default address is 0x450000. address attribute is not ok */

/* add const if you wish the region to be re programmed (tested with pickit4) */
//volatile uint32_t EEPROM_0x45_0000[128] __attribute__((section("nvmsec"),address(0x00450000) )); /* Default address is 0x450000. address attribute is not ok */
uint32_t EEPROM[128] __attribute__((section("nvmsec"),address(0x00450000) )); /* Default address is 0x450000. address attribute is not ok */
const uint32_t* EEPROM_0x45_0000 = EEPROM;
//const uint32_t* EEPROM_0x45_0000 = 0x450000;
static int16_t page_number = -1;

//static uint32_t status = 0;  /* not used with simulink */


//int EFC_PageEraseWrite( uint32_t *data, uint32_t address )

int EFC_PageEraseWrite(uint32_t address)
{

    if (page_number > 0)
        return 1; /* ongoing operation do not operate */

    /*Calculate the Page number to be passed for FARG register*/
    page_number = (address - IFLASH_ADDR) / IFLASH_PAGE_SIZE;

    EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_EPA|EEFC_FCR_FARG(page_number|0x2)|EEFC_FCR_FKEY_PASSWD);           
    /* FLASH Erase & Write operation*/
    
    //EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_EWP | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD); /* Not ok ? */
     
//     for (uint32_t i = 0; i < IFLASH_PAGE_SIZE; i += 4)
//     {
//     *((uint32_t *)( IFLASH_ADDR + ( page_number * IFLASH_PAGE_SIZE ) + i )) =    *(( data++ ));
//     }

    SCB_CleanDCache_by_Addr( (uint32_t*) ((uint32_t) address & 0xFFFFFFE0)  ,IFLASH_PAGE_SIZE);
    
    NVIC_SetPriority(EFC_IRQn, 6u);  /* Scheduler Priority set to 6 */
    NVIC_EnableIRQ(EFC_IRQn);        /*  Enable NVIC line for SysTick  */        
    EFC_REGS->EEFC_FMR |= EEFC_FMR_FRDY_Msk ; /* Enable Interrupt on EFC Ready */
    
    /* for blocking mode, use below and disable interrupt : */
   // while (EFC_REGS->EEFC_FSR & EEFC_FSR_FRDY_Msk == 0);	/* Blocking */
   // EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_WP | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD);
    return 0;
}

void EFC_Handler(void) {
    __ISB();
    __DSB();
    
    EFC_REGS->EEFC_FMR &= ~EEFC_FMR_FRDY_Msk ; /* Disable Interrupt on EFC Ready */        
    EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_WP | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD);	    

    page_number = -1;

    __DSB();
}




/*---------------------------------------*/
/* Below is for reference only. Not used.*/
/*---------------------------------------*/


// 
// 
// void EFC_Initialize(void)
// {
//     EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(6) | EEFC_FMR_CLOE_Msk ;
// }
// bool EFC_Read( uint32_t *data, uint32_t length, uint32_t address )
// {
//     memcpy((void *)data, (void *)address, length);
//     return true;
// }
// 
// bool EFC_SectorErase( uint32_t address )
// {
//     uint16_t page_number;
// 
//     /*Calculate the Page number to be passed for FARG register*/
//     page_number = (address - IFLASH_ADDR) / IFLASH_PAGE_SIZE;
//     /* Issue the FLASH erase operation*/
//     EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_EPA|EEFC_FCR_FARG(page_number|0x2)|EEFC_FCR_FKEY_PASSWD);
// 
//     status = 0;
// 
// 
//     return true;
// }
// 
// bool EFC_PageWrite( uint32_t *data, uint32_t address )
// {
//     uint16_t page_number;
// 
//     /*Calculate the Page number to be passed for FARG register*/
//     page_number = (address - IFLASH_ADDR) / IFLASH_PAGE_SIZE;
// 
//     for (uint32_t i = 0; i < IFLASH_PAGE_SIZE; i += 4)
//     {
//     *((uint32_t *)( IFLASH_ADDR + ( page_number * IFLASH_PAGE_SIZE ) + i )) =    *(( data++ ));
//     }
// 
//     __DSB();
//     __ISB();
// 
//     SCB_CleanDCache_by_Addr( (uint32_t*) ((uint32_t) address & 0xFFFFFFE0)  ,IFLASH_PAGE_SIZE);
    // 
//     /* Issue the FLASH write operation*/
//     EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_WP | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD);
// 
// 
//     status = 0;
// 
// 
//     return true;
// }
// 
// bool EFC_QuadWordWrite( uint32_t *data, uint32_t address )
// {
//     uint16_t page_number;
// 
//     /*Calculate the Page number to be passed for FARG register*/
//     page_number = (address - IFLASH_ADDR) / IFLASH_PAGE_SIZE;
// 
//     for (uint32_t i = 0; i < 16; i += 4)
//     {
//     *((uint32_t *)(( address ) + i )) =    *((uint32_t *)( data++ ));
//     }
//     /* Issue the FLASH write operation*/
//     EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_WP | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD);
// 
//     status = 0;
// 
// 
//     return true;
// }
// 
// void EFC_RegionLock(uint32_t address)
// {
//     uint16_t page_number;
// 
//     /*Calculate the Page number to be passed for FARG register*/
//     page_number = (address - IFLASH_ADDR) / IFLASH_PAGE_SIZE;
//     EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_SLB | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD);
// 
//     status = 0;
// 
// }
// 
// void EFC_RegionUnlock(uint32_t address)
// {
//     uint16_t page_number;
// 
//     /*Calculate the Page number to be passed for FARG register*/
//     page_number = (address - IFLASH_ADDR) / IFLASH_PAGE_SIZE;
//     EFC_REGS->EEFC_FCR = (EEFC_FCR_FCMD_CLB | EEFC_FCR_FARG(page_number)| EEFC_FCR_FKEY_PASSWD);
// 
//     status = 0;
// 
// }
// 
// bool EFC_IsBusy(void)
// {
//     status |= EFC_REGS->EEFC_FSR;
//     return (bool)(!(status & EEFC_FSR_FRDY_Msk));
// }
// 
// EFC_ERROR EFC_ErrorGet( void )
// {
//     status |= EFC_REGS->EEFC_FSR;
//     return (EFC_ERROR)status;
// }
// 
// 
