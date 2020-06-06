/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#define SAPI_USE_INTERRUPTS
#include "rtos.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "sapi.h"
#include "semphr.h"
#include "userTasks.h"
#include "sapi_print.h"
#include "supporting_functions.h"



/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

SemaphoreHandle_t SEM1;
SemaphoreHandle_t SEM2;

void onRxBt( void *noUsado )
{
	BaseType_t despiertoprima=pdFALSE;
	static uint8_t nRecepcion;
    static uint8_t vec[20];
	char f = uartRxRead( UART_232 );
	vec[nRecepcion]=f;
	nRecepcion=nRecepcion+1;
	if((f == '#')||(nRecepcion>19))
	{
		if(vec[0]=='$')
		{
			if(vec[1]=='A')
			{
				xSemaphoreGiveFromISR(SEM1,&despiertoprima);
			}
			if(vec[1]=='B')
			{
				xSemaphoreGiveFromISR(SEM2,&despiertoprima);
			}
		}
		nRecepcion=0;
	}
	//printf( "Recibimos <<%c>> por UART\r\n", f);
	portYIELD_FROM_ISR(despiertoprima);
}
void onRx( void *noUsado )
{
	BaseType_t despierto=pdFALSE;
	static uint8_t nRecepcion;
    static uint8_t vec[20];
	char c = uartRxRead( UART_USB );
	vec[nRecepcion]=c;
	nRecepcion=nRecepcion+1;
	if((c == '#')||(nRecepcion>19))
	{
		if(vec[0]=='$')
		{
			if(vec[1]=='A')
			{
				xSemaphoreGiveFromISR(SEM1,&despierto);
			}
			if(vec[1]=='B')
			{
				xSemaphoreGiveFromISR(SEM2,&despierto);
			}
		}
		nRecepcion=0;
	}
	//printf( "Recibimos <<%c>> por UART,%u\r\n", c,nRecepcion );
	portYIELD_FROM_ISR(despierto);
}
int main( void )
{


	   SEM1=xSemaphoreCreateBinary();

	   SEM2=xSemaphoreCreateBinary();

	   boardInit();
	   /* Inicializar la UART_USB junto con las interrupciones de Tx y Rx */
	   uartConfig(UART_USB, 9600);
	   // Seteo un callback al evento de recepcion y habilito su interrupcion
	   uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
	   // Habilito todas las interrupciones de UART_USB
	   uartInterrupt(UART_USB, true);

	   /* Inicializar la UART_USB junto con las interrupciones de Tx y Rx */
	   uartConfig(UART_232, 9600);
	   // Seteo un callback al evento de recepcion y habilito su interrupcion
	   uartCallbackSet(UART_232, UART_RECEIVE, onRxBt, NULL);
	   // Habilito todas las interrupciones de UART_USB
	   uartInterrupt(UART_232, true);


   // Create a task in freeRTOS with dynamic memory
	   BaseType_t tarea1=xTaskCreate(
			   ledOn,                     // Function that implements the task.
			   (const char *)"ENCENDER LUZ",     // Text name for the task.
			   configMINIMAL_STACK_SIZE*2, // Stack size in words, not bytes.
			   0,                          // Parameter passed into the task.
			   tskIDLE_PRIORITY+1,         // Priority at which the task is created.
			   0                           // Pointer to the task created in the system
	   );
	   BaseType_t tarea3=xTaskCreate(
			   ledOff,                     // Function that implements the task.
			   (const char *)"APAGAR LUZ",     // Text name for the task.
			   configMINIMAL_STACK_SIZE*2, // Stack size in words, not bytes.
			   0,                          // Parameter passed into the task.
			   tskIDLE_PRIORITY+1,         // Priority at which the task is created.
			   0                           // Pointer to the task created in the system
	   );
	   BaseType_t tarea2  =xTaskCreate(
			   myTask2,                     // Function that implements the task.
			   (const char *)"Aburdrir",     // Text name for the task.
			   configMINIMAL_STACK_SIZE*2, // Stack size in words, not bytes.
			   0,                          // Parameter passed into the task.
			   tskIDLE_PRIORITY+1,         // Priority at which the task is created.
			   0                           // Pointer to the task created in the system
	   );
   if(tarea1 == pdFAIL)
   {
	   printf("No se creo la tarea1");
   }
   else
   {
	   printf(" Creo la tarea1");
   }
   if(tarea2 == pdFAIL)
   {
	   printf("No se creo la tarea2");
   }
   else
   {
	   printf(" Creo la tarea2");
   }

   vTaskStartScheduler(); // Initialize scheduler

   while( true )
	   // If reach heare it means that the scheduler could not start
   {
	   //uartTxWrite(UART_USB,2);
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
