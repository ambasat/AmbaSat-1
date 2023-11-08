/*******************************************************************************
* AmbaSat-1 
* Filename: Debugging.h
*
* This file provides debugging support for AmbaSat-1 and its I2C sensor boards
* 
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#ifndef __Debugging__
#define __Debugging__

#define DEBUGGING 

#ifdef DEBUGGING
    #define PRINT_DEBUG(x)    Serial.print(x)
    #define PRINTLN_DEBUG(x)  Serial.println(x)
    #define PRINT_HEX(x)      Serial.print(x, HEX)
#else
    #define PRINT_DEBUG(x)    
    #define PRINTLN_DEBUG(x)  
    #define PRINT_HEX(x)      
#endif

#endif  // __Debugging__
