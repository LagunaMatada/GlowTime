/*******************************************************************************
* File Name: ADC_P2_4.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ADC_P2_4.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ADC_P2_4_PC =   (ADC_P2_4_PC & \
                                (uint32)(~(uint32)(ADC_P2_4_DRIVE_MODE_IND_MASK << (ADC_P2_4_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ADC_P2_4_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ADC_P2_4_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void ADC_P2_4_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ADC_P2_4_DR & (uint8)(~ADC_P2_4_MASK));
    drVal = (drVal | ((uint8)(value << ADC_P2_4_SHIFT) & ADC_P2_4_MASK));
    ADC_P2_4_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ADC_P2_4_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void ADC_P2_4_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ADC_P2_4__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ADC_P2_4_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ADC_P2_4_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADC_P2_4_Read(void) 
{
    return (uint8)((ADC_P2_4_PS & ADC_P2_4_MASK) >> ADC_P2_4_SHIFT);
}


/*******************************************************************************
* Function Name: ADC_P2_4_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ADC_P2_4_ReadDataReg(void) 
{
    return (uint8)((ADC_P2_4_DR & ADC_P2_4_MASK) >> ADC_P2_4_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADC_P2_4_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADC_P2_4_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ADC_P2_4_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ADC_P2_4_INTSTAT & ADC_P2_4_MASK);
		ADC_P2_4_INTSTAT = maskedStatus;
        return maskedStatus >> ADC_P2_4_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
