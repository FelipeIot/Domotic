/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __TIRALED_H__
#define __TIRALED_H__

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

   uint8_t  red; /* 0 to 7   */
   uint8_t  green;	 /* 0 to 7   */
   uint8_t  blue;	 /* 0 to 7    */

} rgb_t;
/*=====[Public function-like macros]=========================================*/



/*=====[Definitions of public data types]====================================*/
extern rgb_t tira;
extern uint8_t redcorrection[8];
extern uint8_t greencorrection[8];
extern uint8_t bluecorrection[8];
extern void tiraled_init(void);
/*=====[Prototypes (declarations) of public functions]=======================*/


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __RTOS_H__ */
