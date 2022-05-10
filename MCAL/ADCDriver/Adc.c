/**
 * @file Adc.c
 * @author Mina-Ryad (mina.hany.kameel.ryad@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-05-09
 * 
 * @copyright Mina-Ryad (c) 2022
 * 
 */

#include "Adc.h"

/**
 * @brief Function API to Start ADC Conversion
 * 
 * @param Group 
 * Section: 8.3.4
 * Service Name: Adc_StartGroupConversion
 * Syntax: void Adc_StartGroupConversion( Adc_GroupType Group )
 * Description: Starts the conversion of all channels of the requested ADC Channel group.
 * Available via: Adc.h
 */

void Adc_StartGroupConversion( Adc_GroupType Group )
{
    if(Group==1)
    {
        /* Write our Code to start ADC */
    }
}

/**
 * @brief 
 * 
 * @param Group 
 * @param DataBufferPtr 
 * @return Std_ReturnType 
 * Section: 8.3.6
 * Service Name: Adc_ReadGroup
 * Syntax: Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
 * Description: Reads the group conversion result of the last completed conversion round of the 
 *              requested group and stores the channel values starting at the DataBufferPtr address. 
 *              The group channel values are stored in ascending channel number order 
 *              ( in contrast to the storage layout of the result buffer if streaming access is configured).
 * Available via: Adc.h
 */

Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
{
    int ADCValue;
    if(Group == 1)
    {
        ADCValue = SomeRegister;
        *DataBufferPtr = ADCValue;
    }
}