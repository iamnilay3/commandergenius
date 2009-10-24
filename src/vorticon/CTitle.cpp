/*
 * CTitle.cpp
 *
 *  Created on: 03.10.2009
 *      Author: gerstrong
 *
 * See CTitle.h for more information
 */

#include "CTitle.h"
#include "../sdl/CTimer.h"
#include "../sdl/CVideoDriver.h"
#include "ai/CEGABitmap.h"

////
// Creation Routine
////
CTitle::CTitle(std::vector<CObject*> *pObjects) {
	m_finished = false;
	m_time = 0;
	mp_objects = pObjects;
}

bool CTitle::init()
{
CObject *p_object;
SDL_Surface *pSurface;
CBitmap *pBitmap;
	g_pTimer->ResetSecondsTimer();
	m_time = 10; // show the title screen for 10 sec
	pSurface = g_pVideoDriver->BlitSurface;

	pBitmap = g_pGfxEngine->getBitmap("TITLE");
	p_object = new CEGABitmap( pSurface, pBitmap );
	p_object->setPos( 160-(pBitmap->getWidth()/2), 0 );
	mp_objects->push_back(p_object);

	pBitmap = g_pGfxEngine->getBitmap("F1HELP");
	p_object = new CEGABitmap( pSurface, pBitmap );
	p_object->setPos( 96, 180 );
	mp_objects->push_back(p_object);

	return true;
}

////
// Process Routine
////
void CTitle::process()
{
	if( m_time == 0) m_finished = true;
	else m_time -= g_pTimer->HasSecElapsed();
}

////
// Cleanup Routine
////
void CTitle::cleanup()
{
	while( !mp_objects->empty() )
	{
		delete *( mp_objects->end() );
		mp_objects->pop_back();
	}
}

CTitle::~CTitle() {

}

