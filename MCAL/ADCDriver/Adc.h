/**
 * @file Adc.h
 * @author Mina-Ryad (mina.hany.kameel.ryad@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-05-09
 * 
 * @copyright Mina-Ryad (c) 2022
 * 
 */

/**
 * Section: 8.2.3
 * Name: Adc_GroupType
 * Type: uint
 * Range: The range of this type is μC specific and has to be described by the supplier.
 * Description: Numeric ID of an ADC channel group.
 * Available via: Adc.h
 */

typedef unsigned int Adc_GroupType;

/**
 * Section: 8.2.4
 * Name: Adc_ValueGroupType
 * Type: int
 * Range: Implementation specific.
 * Description: Type for reading the converted values of a channel group 
 *              (raw, without further scaling, alignment according precompile switch ADC_RESULT_ALIGNMENT).
 * Available via: Adc.h
 */

typedef int Adc_ValueGroupType;