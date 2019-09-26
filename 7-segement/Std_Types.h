 /******************************************************************************
 *
 * Module: Common - Platform
 *
 * File Name: Std_Types.h
 *
 * Description: General type definitions
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/*
 *  Describes the standard Return Type Definitions used in the project
 */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define NA			0xff


typedef unsigned char         boolean;
typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define E_OK            ((uint8)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((uint8)0x01U)      /* Function Return NOT OK */

typedef enum
{
	NOK,OK
}Std_Func_t;

#endif /* STD_TYPES_H */
