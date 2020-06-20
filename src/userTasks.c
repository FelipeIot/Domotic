/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/

#include "userTasks.h"

#include "sound.h"
 #include "supporting_functions.h"
#include "sapi.h"
#include "rtcLayer.h"
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
    	gpioWrite( T_FIL2, ON );//encender foco
    }
}
void ledOff( void* taskParmPtr )
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEM2,portMAX_DELAY);
    	gpioWrite( T_FIL2, OFF );//apagar foco
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
        printf("%02d/%02d/%04d, %02d:%02d:%02d\r\n",rtc.mday, rtc.month, rtc.year,rtc.hour, rtc.min, rtc.sec );//imprimir time
        taskEXIT_CRITICAL();
        vTaskDelay( 500 / portTICK_RATE_MS );
        gpioWrite( LEDB ,0 );
        vTaskDelayUntil( &xLastWakeTime , xPeriodicity );
    }
}

void manejoDeLed( void* taskParmPtr )//actualiza tira led
{

	TickType_t periodo =  200/ portTICK_RATE_MS;
    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEMLED,periodo);
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
 	   pwmWrite( PWM0, redcorrection[tira.red]);
 	   pwmWrite( PWM1, bluecorrection[tira.blue]);
 	   pwmWrite( PWM2, greencorrection[tira.green] );
    }
}

void playMarioSound( void* taskParmPtr )//toca canción de mario
{

    TickType_t periodo =  1/ portTICK_RATE_MS;		// Tarea periodica cada 1 ms


    static uint16_t contadorMilisegundos=0;
    static uint16_t indice;
    static bool_t variante=TRUE;




    procesartabla(&melody[0],&tempo[0],&frecuencia[0],&milis[0],78,1100);

    // ---------- REPETIR POR SIEMPRE --------------------------
    indice=0;
    while(TRUE)
    {

    xSemaphoreTake(SEMTONEMARIO,portMAX_DELAY);


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

void playMemeSound( void* taskParmPtr )//toca canción meme
{




    static uint16_t contadorMilisegundos=0;
    static uint16_t indice;
    static bool_t variante=TRUE;




    procesartabla(&melodyMeme[0],&tempoMeme[0],&frecuenciaMeme[0],&milisMeme[0],136,800);

    // ---------- REPETIR POR SIEMPRE --------------------------
    indice=0;
    while(TRUE)
    {

    xSemaphoreTake(SEMTONEMEME,portMAX_DELAY);


		while(TRUE)
		{

			vTaskDelay( 1 / portTICK_RATE_MS );

			contadorMilisegundos++;
			variante = TRUE;
			if(contadorMilisegundos>milisMeme[indice])
			{
				contadorMilisegundos=0;
				indice++;
				if(indice>271)
				{
					indice=0;
					break;
				}
				   Sct_Init( frecuenciaMeme[indice]);
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

void cortinaOpen( void* taskParmPtr )//abre cortina
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEMCORTINAOPEN,portMAX_DELAY);
    	gpioWrite( LED1, ON );
    }
}
void cortinaClose( void* taskParmPtr )//cierra cortina
{


    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEMCORTINACLOSE,portMAX_DELAY);
    	gpioWrite( LED1, OFF );
    }
}

void alarma( void* taskParmPtr )//dispara alarma
{

	 TickType_t periodo =  30000 / portTICK_RATE_MS;	//cada 30 segundos
    // ---------- REPETIR POR SIEMPRE --------------------------
    while( TRUE )
    {
    	xSemaphoreTake(SEMDESPERTADOR,periodo);
    	if((despertador.hour==rtc.hour)&&(despertador.min==rtc.min))
    	{
    		xSemaphoreGive(SEMTONEMARIO);
    	}
    }
}
/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

