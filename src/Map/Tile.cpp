/*
 * Tile.cpp
 *
 *  Created on: Jul 13, 2026
 *      Author: ASRCFH\bberger
 */

#include "Tile.h"

Tile::Tile(int newTileID, Coord newCoord)
    : tileID(newTileID), coord(newCoord)
{}

Tile::Tile()
    : tileID(-1)
{
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

