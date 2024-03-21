#ifndef _COMMON_H_
#define _COMMON_H_
//==============================================================================================================================================================
typedef enum
{
  BASE_STATUS_UNKNOWN           = 0xFF,
  BASE_STATUS_DONE              = 0,
  BASE_STATUS_RETRY             = 1,
  BASE_STATUS_FAILED            = 2,
  BASE_STATUS_TIMEOUT           = 3,
  BASE_STATUS_PACKET_TIMEOUT    = 4,
  BASE_STATUS_BUSY              = 5,
} BASE_STATUS;
//==============================================================================================================================================================
#ifndef uint8_t
  #define uint8_t                       unsigned char
  #define int8_t                        signed char
#endif
#ifndef uint16_t
  #define uint16_t                      unsigned short
  #define int16_t                       signed short
#endif
#ifndef uint32_t
  #define uint32_t                      unsigned long
  #define int32_t                       signed long
#endif
//==============================================================================================================================================================
#ifndef bool
  typedef enum
  {
    false               = 0,
    true,
  } bool;
#endif
//==============================================================================================================================================================
typedef struct
{
  unsigned short Length;
  unsigned char* Data;
} String_TypeDef;
//==============================================================================================================================================================
#ifndef NULL
  #define NULL          (void*)0
#endif
//==============================================================================================================================================================
#define BITN            0x00
#ifndef BIT7
  #define BIT0          (0x01 << 0)
  #define BIT1          (0x01 << 1)
  #define BIT2          (0x01 << 2)
  #define BIT3          (0x01 << 3)
  #define BIT4          (0x01 << 4)
  #define BIT5          (0x01 << 5)
  #define BIT6          (0x01 << 6)
  #define BIT7          (0x01 << 7)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef BIT15
  #define BIT8          (0x0001 << 8)
  #define BIT9          (0x0001 << 9)
  #define BIT10         (0x0001 << 10)
  #define BIT11         (0x0001 << 11)
  #define BIT12         (0x0001 << 12)
  #define BIT13         (0x0001 << 13)
  #define BIT14         (0x0001 << 14)
  #define BIT15         (0x0001 << 15)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef BIT31
  #define BIT16         (0x000001 << 16)
  #define BIT17         (0x000001 << 17)
  #define BIT18         (0x000001 << 18)
  #define BIT19         (0x000001 << 19)
  #define BIT20         (0x000001 << 20)
  #define BIT21         (0x000001 << 21)
  #define BIT22         (0x000001 << 22)
  #define BIT23         (0x000001 << 23)

  #define BIT24         (0x00000001 << 24)
  #define BIT25         (0x00000001 << 25)
  #define BIT26         (0x00000001 << 26)
  #define BIT27         (0x00000001 << 27)
  #define BIT28         (0x00000001 << 28)
  #define BIT29         (0x00000001 << 29)
  #define BIT30         (0x00000001 << 30)
  #define BIT31         (0x00000001 << 31)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ARR_LEN(Array)  (sizeof(Array) / sizeof(Array[0]))
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <define.h>
#define BIT(index_start, index_end)     REPLACE_COMMA(PARAMS_COUNT(PARAMS_GET_FROM(index_start,PARAMS_GET_TO_A1(index_end,BIT_DATA()))),|,PARAMS_GET_FROM(index_start,PARAMS_GET_TO_A1(index_end,BIT_DATA())))
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef WO              //Write only
  #define WO            //
#endif
#ifndef CLR_1           //Clear by write 1
  #define CLR_1         //
#endif
#ifndef SET_0           //Set by write 0
  #define SET_0         //
#endif
#ifndef TOG             //Only change by toggle
  #define TOG           //
#endif
//==============================================================================================================================================================
//======================================================               FOR COMPILER                   ==========================================================
//===========================================          more: https://sourceforge.net/p/predef/wiki/Compilers/   ================================================
//==============================================================================================================================================================  
/*
 _______________________________________________________________________________________________________________________
|___________ Keyword __________|_____________________________________ Description ______________________________________|
|   __no_init                  |  Declare variables but not auto store value by compiler's code                         |
|______________________________|________________________________________________________________________________________|
|   __root                     |  Make sure variables existed                                                           |
|______________________________|________________________________________________________________________________________|
|   __weak                     |  Function can be override                                                              |
|______________________________|________________________________________________________________________________________|
|   __packed                   |  Absolute pack in byte (non auto align)                                                |
|______________________________|________________________________________________________________________________________|
|   __at(Address)              |  Absolute address of variables                                                         |
|______________________________|________________________________________________________________________________________|
|   __gptr                     |  General pointer to all memory area (only for 8051 structure)                          |
|______________________________|________________________________________________________________________________________|
|   __xdata                    |  Object store at xdata area (only for 8051 structure)                                  |
|______________________________|________________________________________________________________________________________|
|   __sfr                      |  Object store at speccial function register area (only for 8051 structure)             |
|______________________________|________________________________________________________________________________________|
|   __data                     |  Object store at data area (only for 8051 structure)                                   |
|______________________________|________________________________________________________________________________________|
|   __code                     |  Object store at code area (must const) (only for 8051 structure)                      |
|______________________________|________________________________________________________________________________________|
|   __bit                      |  Object store at bit area (only for 8051 structure)                                    |
|______________________________|________________________________________________________________________________________|
|   __eeprom                   |  Object store at eeprom area                                                           |
|______________________________|________________________________________________________________________________________|
*/
#if (__IAR_SYSTEMS_ICC__)
/*     IAR  for STM8   */
  #if (__ICCSTM8__)
    #define CORE_SIZE           1
    #define VARS_ORG            1       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
//    #define __weak              //
    #define __packed            //
    #define __at(Address)       @ Address
    #define __gptr              //
    #define __xdata             //
    #define __sfr               //
    #define __data              //
    #define __code              //
    #define __bit               //
//    #define __eeprom            //
/*     IAR  for 8051   */
  #elif (__ICC8051__)
    #define CORE_SIZE           1
    #define VARS_ORG            0       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
    #define __weak            //
    #define __packed            //
    #define __at(Address)       @ Address
    #define __gptr              __generic
//    #define __xdata             //
//    #define __sfr               //
//    #define __data              //
//    #define __code              //
//    #define __bit               //
    #define __eeprom            //
/*     IAR  for AVR   */
  #elif (__ICCAVR__)
    #define CORE_SIZE           1
    //#define VARS_ORG            1       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
//    #define __weak              //
    #define __packed            //
    #define __at(Address)       @ Address
    #define __gptr              //
    #define __xdata             //
    #define __sfr               //
    #define __data              //
    #define __code              //
    #define __bit               //
    #define __eeprom            //
/*     IAR  for MSP430   */
  #elif (__ICC430__)  
    #define CORE_SIZE           2
    //#define VARS_ORG            1       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
//    #define __weak              //
    #define __packed            //
    #define __at(Address)       @ Address
    #define __gptr              //
    #define __xdata             //
    #define __sfr               //
    #define __data              //
    #define __code              //
    #define __bit               //
    #define __eeprom            //
/*     IAR  for ARM   */
  #elif (__ICCARM__)
    #define CORE_SIZE           4
    #define VARS_ORG            0       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
//    #define __weak              //
//    #define __packed            //
    #define __at(Address)       @ Address
    #define __gptr              //
    #define __xdata             //
    #define __sfr               //
    #define __data              //
    #define __code              //
    #define __bit               //
    #define __eeprom            //
  #endif
/*     KEIL C for 8051  */
#elif (__C51__)
    #define CORE_SIZE           1
    //#define VARS_ORG            1       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
//    #define __weak              //
//    #define __packed            //
//    #define __at(Address)       @ Address
//    #define __gptr              //
//    #define __xdata             //
//    #define __sfr               //
//    #define __data              //
//    #define __code              //
//    #define __bit               //
//    #define __eeprom            //
/*     KEIL C for ARM   */
#elif (__KEIL__)
    #define CORE_SIZE           4
    //#define VARS_ORG            1       //variables organization (ex: unsigned long Var) at Max-Byte-First(1) or Low-Byte-First(0)
//    #define __no_init
//    #define __root
//    #define __weak              //
//    #define __packed            //
//    #define __at(Address)       @ Address
//    #define __gptr              //
//    #define __xdata             //
//    #define __sfr               //
//    #define __data              //
//    #define __code              //
//    #define __bit               //
//    #define __eeprom            //
#endif

#if (CORE_SIZE == 8)                            //64-bit
  #define reg8        unsigned long long
  #define reg8s       signed long long
  #define reg16       unsigned long long
  #define reg16s      signed long long
  #define reg32       unsigned long long
  #define reg32s      signed long long
  #define reg64       unsigned long long
  #define reg64s      signed long long
#elif (CORE_SIZE == 4)                          //32-bit
  #define reg8        unsigned long
  #define reg8s       signed long
  #define reg16       unsigned long
  #define reg16s      signed long
  #define reg32       unsigned long
  #define reg32s      signed long
  #define reg64       unsigned long long
  #define reg64s      signed long long
#elif (CORE_SIZE == 2)                          //16-bit
  #define reg8        unsigned short
  #define reg8s       signed short
  #define reg16       unsigned short
  #define reg16s      signed short
  #define reg32       unsigned long
  #define reg32s      signed long
  #define reg64       //
  #define reg64s      //
#elif (CORE_SIZE == 1)                          //8-bit
  #define reg8        unsigned char
  #define reg8s       signed char
  #define reg16       unsigned short
  #define reg16s      signed short
  #define reg32       unsigned long
  #define reg32s      signed long
  #define reg64       //
  #define reg64s      //
#endif
//==============================================================================================================================================================
typedef struct
{
  struct
  {
    unsigned char MSB[8];
    unsigned char LSB[8];
  } NonReverse;
  struct
  {
    unsigned char MSB[8];
    unsigned char LSB[8];
  } Reverse;
} BitArray_TypeDef;
extern const BitArray_TypeDef __code BitArray;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
typedef struct
{
  struct
  {
    unsigned char MSB[9];
    unsigned char LSB[9];
  } NonReverse;
  struct
  {
    unsigned char MSB[9];
    unsigned char LSB[9];
  } Reverse;
} BitGroup_TypeDef;
extern const BitGroup_TypeDef __code BitGroup;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
extern const unsigned char __code HighBitCount[256];
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
extern const unsigned char __code ReverseByte[256];
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
extern const __code unsigned char HighBitCompare5[32];
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void DelayLoop(reg16 Loop);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//reg16 GetStringLength(const unsigned char __gptr* String, 
//#ifndef GetCharacerWidth
//                      reg8 GetCharacerWidth(reg8 Character), 
//#endif
//                      reg8 SpaceWidth);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
+) param:
  max string length: 254
+) return:
  0: string is not match
  1: string1 in string2
  2: string2 in string1
  3: string1 == string2
  4: string1 and string2 exist each other
*/
reg8 CompareString(unsigned char __gptr* String1, unsigned char __gptr* String2);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
+) return:
  0: not match
  else: match
*/
reg8 CompareArray(unsigned char __gptr* Array1, unsigned char __gptr* Array2, reg8 Length);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Storage(unsigned char* Destiny, unsigned char __gptr* Source, reg8 Length);
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif