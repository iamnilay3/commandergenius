/*
 * CLevelPlay.cpp
 *
 *  Created on: 06.08.2010
 *      Author: gerstrong
 */

#include "CLevelPlay.h"
#include "CMapLoaderGalaxy.h"
#include "sdl/CInput.h"
#include "sdl/CVideoDriver.h"

namespace galaxy {

CLevelPlay::CLevelPlay(CExeFile &ExeFile) :
m_active(false),
m_ExeFile(ExeFile)
{ }

bool CLevelPlay::isActive()
{	return m_active;	}

void CLevelPlay::setActive(bool value)
{	m_active = value;	}

bool CLevelPlay::loadLevel(Uint16 level)
{
	// Load the World map level.
	CMapLoaderGalaxy MapLoader(m_ExeFile, m_ObjectPtr);

	m_Map.setScrollSurface(g_pVideoDriver->getScrollSurface());
	MapLoader.loadMap(m_Map, level);

	m_Map.drawAll();
	return true;
}

void CLevelPlay::process()
{
	// Animate the tiles of the map
	m_Map.animateAllTiles();

	for(size_t i=0 ; i<m_ObjectPtr.size() ; i++)
	{
		CObject* p_Object = m_ObjectPtr[i];

		p_Object->process();
	}

	g_pVideoDriver->blitScrollSurface();

	for( std::vector<CObject*>::iterator obj=m_ObjectPtr.begin() ;
			obj!=m_ObjectPtr.end() ; obj++ )
	{
		(*obj)->draw();
	}
}

CLevelPlay::~CLevelPlay() {
	// TODO Auto-generated destructor stub
}

}
