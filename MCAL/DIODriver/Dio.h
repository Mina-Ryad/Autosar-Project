/**
 * @file Dio.h
 * @author Mina-Ryad (mina.hany.kameel.ryad@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-05-09
 * 
 * @copyright Mina-Ryad (c) 2022
 * 
 */

/**
 * Section: 8.2.4
 * Name: Dio_LevelType
 * Type: uint8
 * Range: STD_LOW  - 0x00 - Physical state 0V
 *        STD_HIGH - 0x01 - Physical state 5V or 3.3V
 * Description: These are the possible levels a DIO channel can have (input or output)
 * Available via: Dio.h
 */

typedef unsigned char Dio_LevelType;

#define STD_LOW     0x00
#define STD_HIGH    0x01

/**
 * Section: 8.2.1
 * Name: Dio_ChannelType
 * Type: uint
 * Range: --
 * Description: Numeric ID of a DIO channel.
 * Available via: Dio.h
 */

typedef unsigned int Dio_ChannelType;
