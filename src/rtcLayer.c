/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/05/21
 * Version: 1
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/


#include "sapi.h"
#include "rtcLayer.h"
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
void rtc_config(void)
{
	rtcInit();//configuración inicial rtc
}

void rct_leer(rtclock_t *real)
{
	rtc_t rtc;
	rtcRead( &rtc );
	real->hour=rtc.hour; //hora del rtc
	real->mday=rtc.mday;//dia del rtc
	real->min=rtc.min;//minuto del rtc
	real->month=rtc.month;//mes del rtc
	real->sec=rtc.sec;//segundo del rtc
	real->wday=rtc.wday;//dia de la semana del rtc
	real->year=rtc.year;//año del rtc

}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

