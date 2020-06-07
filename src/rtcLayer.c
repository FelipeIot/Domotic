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
	rtcInit();
}

void rct_leer(rtclock_t *real)
{
	rtc_t rtc;
	rtcRead( &rtc );
	real->hour=rtc.hour;
	real->mday=rtc.mday;
	real->min=rtc.min;
	real->month=rtc.month;
	real->sec=rtc.sec;
	real->wday=rtc.wday;
	real->year=rtc.year;

}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

