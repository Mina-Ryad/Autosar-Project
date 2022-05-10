/**
 * @file Dio.c
 * @author Mina-Ryad (mina.hany.kameel.ryad@gmail.com)
 * @brief MCAL Layer for Dio Driver
 * @version 1.0
 * @date 2022-05-09
 * 
 * @copyright Mina-Ryad (c) 2022
 * 
 */

#include "Dio.h"

/**
 * @brief Function API to read a channel
 * 
 * @param ChannelId - ID of DIO channel
 * @return Dio_LevelType            STD_HIGH The physical level of the corresponding Pin is STD_HIGH 
 *                                  STD_LOW The physical level of the corresponding Pin is STD_LOW 
 * Section: 8.3.1 
 * Service Name: Dio_ReadChannel 
 * Syntax: Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId ) 
 * Description: Returns the value of the specified DIO channel.
 * Available via: Dio.h  
 */

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
    unsigned int ReadVal;

    /* Assume Channel 10 is mapped to P2.0*/
    if(ChannelId == 10)
    {
        ReadVal = P2IN & BIT0;
        if(ReadVal == 0x00) /* If pin is LOW */
        {
            return (STD_LOW);
        }
        else /* If pin is HIGH */
        {
            return (STD_HIGH);
        }
    }
}

/**
 * @brief Function API to write a channel
 *  
 * @param ChannelId - ID of DIO channel
 * @param Level - Value to be written
 * Section: 8.3.2
 * Service Name: Dio_WriteChannel
 * Syntax: void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
 * Description: Service to set a level of a channel.
 * Available via: Dio.h
 */

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    if(ChannelId == 10)
    {
        if(Level == STD_LOW)
        {
            P2OUT &= ~BIT0; /* Code to set pin LOW */
        }
        else /* If pin is HIGH */
        {
            P2OUT |= BIT0; /* Code to set pin HIGH */
        }
    }
}