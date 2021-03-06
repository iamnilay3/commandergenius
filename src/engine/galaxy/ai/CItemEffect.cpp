/*
 * CItemEffect.cpp
 *
 *  Created on: 19.11.2010
 *      Author: gerstrong
 *
 *  This will animate the picked up items. It's basically the same
 *  as CRisingPoints in the Vorticon Engine.
 *  Here we have different cases, because some animations differ
 */

#include "CItemEffect.h"

namespace galaxy {

const int itemEffectTime = 50;
const int itemEffectTime_Animation = 14;

CItemEffect::CItemEffect(CMap *pmap, Uint32 x, Uint32 y, Uint16 l_sprite, item_effect_type ieffect) :
CObject(pmap, x, y, OBJ_NONE)
{
	m_timer = 0;
	sprite = l_sprite-124;
	honorPriority = false;
	solid = false;
	m_ieffect = ieffect;
}

void CItemEffect::process()
{
	if(m_ieffect == FLOAT)
	{
		if(m_timer >= itemEffectTime)
			exists = false;

		moveUp(16);
	}
	else if(m_ieffect == ANIMATE)
	{
		if(m_timer >= itemEffectTime_Animation)
			exists = false;

		if((m_timer%6) == 5)
			sprite++;
	}

	m_timer++;
}

}
