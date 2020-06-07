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
#include "rtcLayer.h"
#include "soundMario.h"
#include "sapi_sct.h"
#include "tiraled.h"
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
    	gpioWrite( LEDR, ON );
    }
}
void ledOff( void* taskParmPtr )
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEM2,portMAX_DELAY);
    	gpioWrite( LEDR, OFF );
    }
}


void myTask2( void* taskParmPtr )
{

    TickType_t xPeriodicity =  1000 / portTICK_RATE_MS;		// Tarea periodica cada 1000 ms

    TickType_t xLastWakeTime = xTaskGetTickCount();

    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
        gpioWrite( LEDB ,1 );

        taskENTER_CRITICAL();
        rct_leer( &rtc );
        printf("%02d/%02d/%04d, %02d:%02d:%02d\r\n",rtc.mday, rtc.month, rtc.year,rtc.hour, rtc.min, rtc.sec );
        taskEXIT_CRITICAL();
        vTaskDelay( 500 / portTICK_RATE_MS );
        gpioWrite( LEDB ,0 );
        // Envia la tarea al estado bloqueado durante xPeriodicity (delay periodico)
        vTaskDelayUntil( &xLastWakeTime , xPeriodicity );
    }
}

void manejoDeLed( void* taskParmPtr )
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEMLED,portMAX_DELAY);
    	if(tira.blue>7)
    	{
    		tira.blue=7;
    	}
    	if(tira.red>7)
    	{
    		tira.red=7;
    	}
    	if(tira.green>7)
    	{
    		tira.green=7;
    	}
 	   pwmWrite( PWM7, redcorrection[tira.red]);
 	   pwmWrite( PWM8, bluecorrection[tira.blue]);
 	   pwmWrite( PWM9, greencorrection[tira.green] );
    }
}



void playMarioSound( void* taskParmPtr )
{

    TickType_t periodo =  1/ portTICK_RATE_MS;		// Tarea periodica cada 1000 ms

    //TickType_t xLastWakeTime = xTaskGetTickCount();
    static uint16_t contadorMilisegundos=0;
    static uint16_t indice;
    static bool_t variante=TRUE;




    procesartabla(&melody[0],&tempo[0],&frecuencia[0],&milis[0],78);

    // ---------- REPETIR POR SIEMPRE --------------------------
    indice=0;
    while(TRUE)
    {

    xSemaphoreTake(SEMTONEMARIO,portMAX_DELAY);
    //pwmConfig( PWM6, PWM_ENABLE_OUTPUT );

		while(TRUE)
		{

			vTaskDelay( 1 / portTICK_RATE_MS );

			contadorMilisegundos++;
			variante = TRUE;
			if(contadorMilisegundos>milis[indice])
			{
				contadorMilisegundos=0;
				indice++;
				if(indice>155)
				{
					indice=0;
					break;
				}
				   Sct_Init( frecuencia[indice]);
				   if(variante)
				   {
					   pwmWrite( PWM6, 127 );
					   variante = FALSE;
				   }
				   else
				   {
					   pwmWrite( PWM6, 0 );
					   variante = TRUE;
				   }
			}

		}

		pwmWrite( PWM6, 0 );
		Sct_Init( 10000);



    }

}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

