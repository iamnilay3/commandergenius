/*
 * CStatusScreenGalaxyEp4.cpp
 *
 *  Created on: 13.03.2011
 *      Author: gerstrong
 */

#include "CStatusScreenGalaxyEp4.h"
#include "graphics/CGfxEngine.h"
#include "common/CBehaviorEngine.h"
#include "StringUtils.h"

CStatusScreenGalaxyEp4::CStatusScreenGalaxyEp4(const stItemGalaxy& Item, const std::string &LevelName) :
CStatusScreenGalaxy(Item, LevelName)
{}


void CStatusScreenGalaxyEp4::GenerateStatus()
{
	SDL_Rect EditRect;
	drawBase(EditRect);

	SDL_PixelFormat *pixelformat = mp_StatusSurface->format;

	CFont &Font = g_pGfxEngine->getFont(0);
	Font.setBGColour(pixelformat, 0xAAAAAA);
	Font.setFGColour(pixelformat, 0x555555);

	Font.drawFontCentered(mp_StatusSurface, "LOCATION", EditRect.x, EditRect.w, EditRect.y, false);

	// Temporary Rect for drawing some stuff like background for scores and so...
	SDL_Rect TempRect;

	// Location Rect
	TempRect.x = EditRect.x;
	TempRect.y = EditRect.y+10;
	TempRect.w = EditRect.w;
	TempRect.h = 20;

	Font.setBGColour(pixelformat, 0xFFFFFF);
	Font.setFGColour(pixelformat, 0x0);
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFFFFFFFF);
	Font.drawFontCentered(mp_StatusSurface, m_LevelName, TempRect.x, TempRect.w, TempRect.y+6, false);
	Font.setBGColour(pixelformat, 0xAAAAAA);
	Font.setFGColour(pixelformat, 0x555555);


	/// SCORE and EXTRA Rect
	TempRect.x = EditRect.x;
	TempRect.y = EditRect.y+32;
	TempRect.w = EditRect.w/2; TempRect.h = 10;
	Font.drawFont(mp_StatusSurface, "SCORE            EXTRA", TempRect.x+16, TempRect.y);
	TempRect.w = (EditRect.w/2)-16; TempRect.h = 11;
	TempRect.y = EditRect.y+42;

	// Score Box
	TempRect.w = 8*8;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	g_pGfxEngine->drawDigits(getRightAlignedString(itoa(m_Item.m_points), 8), TempRect.x, TempRect.y+2, mp_StatusSurface);

	// Extra Box
	TempRect.x = EditRect.x+96;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	g_pGfxEngine->drawDigits(getRightAlignedString(itoa(m_Item.m_lifeAt), 8), TempRect.x, TempRect.y+2, mp_StatusSurface);

	/// RESCUED and LEVEL Rects
	TempRect.x = EditRect.x;
	TempRect.y = EditRect.y+56;
	TempRect.w = EditRect.w/2; TempRect.h = 10;
	Font.drawFont(mp_StatusSurface, "RESCUED           LEVEL", TempRect.x+8, TempRect.y);
	TempRect.w = (EditRect.w/2)-16; TempRect.h = 11;
	TempRect.y = EditRect.y+66;

	// Rescued Box
	TempRect.w = 8*8;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	for( int count=0 ; count<m_Item.m_special.ep4.elders ; count++ )
		g_pGfxEngine->drawDigit(40, TempRect.x+8*count, TempRect.y+1, mp_StatusSurface);

	// Level Box
	TempRect.x = EditRect.x+96;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFFFFFFFF);
	Font.setBGColour(pixelformat, 0xFFFFFF);
	Font.setFGColour(pixelformat, 0x0);
	std::string difftext;
	if(m_Item.m_difficulty == 1)
		difftext = "Easy";
	else if(m_Item.m_difficulty == 2)
		difftext = "Normal";
	else if(m_Item.m_difficulty == 3)
		difftext = "Hard";
	else
		difftext = "???";
	Font.drawFontCentered(mp_StatusSurface, difftext, TempRect.x, TempRect.w, TempRect.y+1, false);
	Font.setBGColour(pixelformat, 0xAAAAAA);
	Font.setFGColour(pixelformat, 0x555555);

	// Keys Box
	TempRect.x = EditRect.x;
	TempRect.y = EditRect.y+80;
	Font.drawFont(mp_StatusSurface, "KEYS", TempRect.x, TempRect.y);
	TempRect.w = 8*4; TempRect.h = 10;
	TempRect.x = TempRect.x+8*5;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	if(m_Item.m_gem.red)
		g_pGfxEngine->drawDigit(36, TempRect.x, TempRect.y+1, mp_StatusSurface);
	if(m_Item.m_gem.yellow)
		g_pGfxEngine->drawDigit(37, TempRect.x+8, TempRect.y+1, mp_StatusSurface);
	if(m_Item.m_gem.blue)
		g_pGfxEngine->drawDigit(38, TempRect.x+16, TempRect.y+1, mp_StatusSurface);
	if(m_Item.m_gem.green)
		g_pGfxEngine->drawDigit(39, TempRect.x+24, TempRect.y+1, mp_StatusSurface);

	// Ammo Box
	TempRect.x = EditRect.x+96;
	TempRect.y = EditRect.y+80;
	Font.drawFont(mp_StatusSurface, "AMMO", TempRect.x, TempRect.y);
	TempRect.w = 8*3; TempRect.h = 10;
	TempRect.x = TempRect.x+8*5;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	g_pGfxEngine->drawDigits(getRightAlignedString(itoa(m_Item.m_bullets), 3), TempRect.x, TempRect.y+1, mp_StatusSurface);

	// Keens Box
	TempRect.x = EditRect.x;
	TempRect.y = EditRect.y+96;
	Font.drawFont(mp_StatusSurface, "KEENS", TempRect.x, TempRect.y);
	TempRect.w = 8*2; TempRect.h = 10;
	TempRect.x = TempRect.x+8*5+8;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	g_pGfxEngine->drawDigits(getRightAlignedString(itoa(m_Item.m_lifes), 2), TempRect.x, TempRect.y+1, mp_StatusSurface);

	// Drops Box
	TempRect.x = EditRect.x+96;
	TempRect.y = EditRect.y+96;
	Font.drawFont(mp_StatusSurface, "DROPS", TempRect.x, TempRect.y);
	TempRect.w = 8*2; TempRect.h = 10;
	TempRect.x = TempRect.x+8*5+8;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFF000000);
	g_pGfxEngine->drawDigits(getRightAlignedString(itoa(m_Item.m_drops), 2), TempRect.x, TempRect.y+1, mp_StatusSurface);

	// Swim Suit Box
	TempRect.x = EditRect.x;
	TempRect.y = EditRect.y+114;
	TempRect.w = (EditRect.w/2)-16; TempRect.h = 11;
	TempRect.x = TempRect.x;
	SDL_FillRect(mp_StatusSurface, &TempRect, 0xFFFFFFFF);
	Font.setBGColour(pixelformat, 0xFFFFFF);
	Font.setFGColour(pixelformat, 0x0);
	Font.drawFontCentered(mp_StatusSurface, m_Item.m_special.ep4.swimsuit ? "Swim Suit" : "???", TempRect.x, TempRect.w, TempRect.y+1, false);

	// Press a Key Sign
	CTilemap &Tilemap = g_pGfxEngine->getTileMap(2);
	TempRect.x = EditRect.x+(EditRect.w/2);
	TempRect.y = EditRect.y+110;
	for( int c=0 ; c<10 ; c++ )
		Tilemap.drawTile(mp_StatusSurface, TempRect.x+c*8, TempRect.y, 72+c);
	TempRect.y += 8;
	for( int c=0 ; c<10 ; c++ )
		Tilemap.drawTile(mp_StatusSurface, TempRect.x+c*8, TempRect.y, 82+c);
}
