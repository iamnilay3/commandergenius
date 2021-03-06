/*
 * gotpoints.cpp
 *
 *  Created on: 23.08.2009
 *      Author: gerstrong
 */
#include "CRisingPoints.h"

// GotPoints object (rising numbers when you get a bonus item)
// (this wasn't in original Keen)

#define GOTPOINTS_SPEED         16
#define GOTPOINTS_LIFETIME      25
#define YORPSHIELD_LIFETIME     20

CRisingPoints::CRisingPoints(CMap *p_map, Uint32 x, Uint32 y) :
CObject(p_map, x, y, OBJ_GOTPOINTS)
{
	offscreentime = GOTPOINTS_LIFETIME;
	inhibitfall = true;
	solid = false;
	honorPriority = false;
	needinit = 0;
}

void CRisingPoints::process()
{
	moveUp(GOTPOINTS_SPEED);

	// delete it after it's existed for a certain amount of time
	if (!offscreentime)
	{
		exists=false;
		return;
	}
	else offscreentime--;
}
