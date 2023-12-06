/**
 * @file Serial_Communication.h
 * @author Triet NGUYEN (tr_nguye@insa-toulouse.fr)
 * @brief Header for Serial Communication of ESP with Raspberry
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __SERIALCOMM__
#define __SERIALCOMM__
/**
 * @brief Initialize the serial port of ESP8266
 * 
 */
void Serial_Init(void);

/**
 * @brief Send a character to serial bus
 * 
 * @param charToSend 
 */
void Serial_Send(char charToSend);

/**
 * @brief Read a char from the serial bus
 * 
 * @return char 
 */
char Serial_Receive(void);


#endif
