/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/


#include "sapi.h"
#include "soundMario.h"
/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/
uint32_t melody[78] = {NOTE_E7, NOTE_E7, 0, NOTE_E7,0, NOTE_C7, NOTE_E7, 0,NOTE_G7, 0, 0,  0,NOTE_G6, 0, 0, 0,NOTE_C7, 0, 0, NOTE_G6,0, 0, NOTE_E6, 0,0, NOTE_A6, 0, NOTE_B6,0, NOTE_AS6, NOTE_A6, 0,NOTE_G6, NOTE_E7, NOTE_G7,NOTE_A7, 0, NOTE_F7, NOTE_G7,0, NOTE_E7, 0, NOTE_C7,NOTE_D7, NOTE_B6, 0, 0,NOTE_C7, 0, 0, NOTE_G6,0, 0, NOTE_E6, 0,0, NOTE_A6, 0, NOTE_B6,0, NOTE_AS6, NOTE_A6, 0,NOTE_G6, NOTE_E7, NOTE_G7,NOTE_A7, 0, NOTE_F7, NOTE_G7,0, NOTE_E7, 0, NOTE_C7,NOTE_D7, NOTE_B6, 0, 0};
uint16_t tempo[78] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,};
uint32_t frecuencia[156];
uint16_t milis[156];
/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

// Task implementation
void procesartabla(uint32_t *mel,uint16_t *tem,uint32_t *melsal,uint16_t *temsal,uint16_t longitud)
{
	static uint16_t i;
	for(i=0;i<longitud;i++)
	{
		if(mel[i]==0)
		{
			melsal[2*i]=1;
		}
		else
		{
			melsal[2*i]=mel[i];
		}
		if(mel[i]==0)
		{
			melsal[2*i+1]=1;
		}
		else
		{
			melsal[2*i+1]=mel[i];
		}
	}

	for(i=0;i<longitud;i++)
	{
		temsal[2*i]=1200/tem[i];
		temsal[2*i+1]=tem[i]*1.3;
	}

}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

