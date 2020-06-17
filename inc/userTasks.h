/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __USER_TASKS_H__
#define __USER_TASKS_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include "FreeRTOS.h"
#include "task.h"
#include "sapi.h"

#include "semphr.h"
/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
extern SemaphoreHandle_t SEM1;
extern SemaphoreHandle_t SEM2;
extern SemaphoreHandle_t SEMTONEMARIO;
extern SemaphoreHandle_t SEMTONEMEME;
extern SemaphoreHandle_t SEMLED;
extern SemaphoreHandle_t SEMCORTINAOPEN;
extern SemaphoreHandle_t SEMCORTINACLOSE;
extern SemaphoreHandle_t SEMDESPERTADOR;
/*=====[Prototypes (declarations) of public functions]=======================*/
void alarma( void* taskParmPtr );
void ledOn( void* taskParmPtr );  // Task declaration
void ledOff( void* taskParmPtr );  // Task declaration
void myTask2( void* taskParmPtr );  // Task declaration
void playMarioSound( void* taskParmPtr );
void playMemeSound( void* taskParmPtr );
void manejoDeLed( void* taskParmPtr );
void cortinaOpen( void* taskParmPtr );
void cortinaClose( void* taskParmPtr );


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __USER_TASKS_H__ */
