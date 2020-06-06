/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/

#include "userTasks.h"
 #include "supporting_functions.h"
#include "sapi.h"
/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

// Task implementation
void ledOn( void* taskParmPtr )
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEM1,portMAX_DELAY);
    	gpioWrite( LED1, ON );
    }
}
void ledOff( void* taskParmPtr )
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEM2,portMAX_DELAY);
    	gpioWrite( LED1, OFF );
    }
}
void myTask2( void* taskParmPtr )
{
    //gpioWrite( LED1, ON );
    //vTaskDelay( 1000 / portTICK_RATE_MS );	 					// Envia la tarea al estado bloqueado durante 1 s (delay)
    //gpioWrite( LED1, OFF );


    TickType_t xPeriodicity =  1000 / portTICK_RATE_MS;		// Tarea periodica cada 1000 ms

    TickType_t xLastWakeTime = xTaskGetTickCount();

    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
        gpioWrite( LEDB ,1 );
        vTaskDelay( 500 / portTICK_RATE_MS );
        gpioWrite( LEDB ,0 );
        //xSemaphoreGive(SEM1);

        //vPrintString("Hola me llamo ichigo \n" );

        // Envia la tarea al estado bloqueado durante xPeriodicity (delay periodico)
        vTaskDelayUntil( &xLastWakeTime , xPeriodicity );
    }
}


/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

