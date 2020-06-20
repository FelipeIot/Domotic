/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 * http://tronicslab.com/gamma-correction-pulsing-leds/
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/


#include "sapi.h"
#include "tiraled.h"
/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/
uint8_t redcorrection[8]={0,  5,  21,  47,  83,  130,  187,  255};//niveles de iluminación rojo
uint8_t greencorrection[8]={0,  5,  21,  47,  83,  130,  187,  255};//niveles de iluminación verde
uint8_t bluecorrection[8]={0,  5,  21,  47,  83,  130,  187,  255};//niveles de iluminación azul
/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

void tiraled_init(void)//configuración inicial de las tiras led
{
	   bool_t valor = 0;
	   valor = pwmConfig( 0, PWM_ENABLE );
	   valor = pwmConfig( PWM6, PWM_ENABLE_OUTPUT );
	   valor = pwmConfig( PWM0, PWM_ENABLE_OUTPUT );
	   valor = pwmConfig( PWM1, PWM_ENABLE_OUTPUT );
	   valor = pwmConfig( PWM2, PWM_ENABLE_OUTPUT );
	   valor = pwmWrite( PWM0, 255 );
	   valor = pwmWrite( PWM1, 100 );
	   valor = pwmWrite( PWM2, 50 );

}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

