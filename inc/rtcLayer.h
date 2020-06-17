/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __RTCLAYER_H__
#define __RTCLAYER_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include "FreeRTOS.h"


/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/
typedef struct {
   uint16_t year;	 /* 1 to 4095 */
   uint8_t  month; /* 1 to 12   */
   uint8_t  mday;	 /* 1 to 31   */
   uint8_t  wday;	 /* 1 to 7    */
   uint8_t  hour;	 /* 0 to 23   */
   uint8_t  min;	 /* 0 to 59   */
   uint8_t  sec;	 /* 0 to 59   */
} rtclock_t;

typedef struct {
   uint8_t  hour;	 /* 0 to 23   */
   uint8_t  min;	 /* 0 to 59   */
} alarma_t;


/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
extern rtclock_t rtc;
extern alarma_t despertador;
extern void rct_leer(rtclock_t *real);
/*=====[Prototypes (declarations) of public functions]=======================*/
extern void rtc_config(void);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __RTOS_H__ */
