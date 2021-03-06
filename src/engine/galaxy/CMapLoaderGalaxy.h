/*
 * CMapLoaderGalaxy.h
 *
 *  Created on: 29.05.2010
 *      Author: gerstrong
 */

#ifndef CMAPLOADERGALAXY_H_
#define CMAPLOADERGALAXY_H_

#include "fileio/CExeFile.h"
#include "fileio/TypeDefinitions.h"
#include "common/CMap.h"
#include "common/Cheat.h"
#include "engine/galaxy/CInventory.h"
#include "common/CObject.h"
#include <vector>

#include <string>
#include <SDL.h>

namespace galaxy
{

class CMapLoaderGalaxy
{
public:
	CMapLoaderGalaxy(CExeFile &ExeFile, std::vector<CObject*>& ObjectPtr,
			CInventory &Inventory, stCheat &Cheatmode);
	size_t getMapheadOffset();
	bool gotoSignature(std::ifstream &MapFile);
	bool loadMap(CMap &Map, Uint8 level);
	void spawnFoes(CMap &Map);
	void addFoe(CMap &Map, word foe, size_t x, size_t y);

private:
	void unpackPlaneData(std::ifstream &MapFile,
			CMap &Map, size_t PlaneNumber,
			longword offset, longword length,
			word magic_word);

	CExeFile &m_ExeFile;
	std::vector<CObject*>& m_ObjectPtr;
	CInventory &m_Inventory;
	stCheat &m_Cheatmode;
};

}

#endif /* CMAPLOADERGALAXY_H_ */
