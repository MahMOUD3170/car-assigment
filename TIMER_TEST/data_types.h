/*
 * data_types.h
 *
 * Created: 7/10/2019 9:12:49 PM
 *  Author: M_Moawad
 */ 


#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_


/***** Unsigned data types ********/
typedef unsigned char      UINT8  ;
typedef unsigned short     UINT16 ;
typedef unsigned long      UINT32 ;
typedef unsigned long long UINT64 ;
/***********************************/

/****** Signed data types **********/
typedef signed char        SINT8  ;
typedef signed short       SINT16 ;
typedef signed long        SINT32 ;
typedef signed long long   SINT64 ;
/***********************************/

/*** Declaration of Boolean variable ***/
typedef enum{
	false = 0, FALSE = 0,true = 1, TRUE = 1   /* To avoid case sensitive*/
}bool;
/***************************************/




#endif /* DATA_TYPES_H_ */