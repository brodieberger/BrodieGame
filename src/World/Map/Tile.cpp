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
    : tileID(-1),
      coord(-1, -1)
{
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

bool Tile::hasPlayer() const
{
    return std::any_of(
        occupants.begin(),
        occupants.end(),
        [](const GamePiece* piece)
        {
            return piece->getPieceType() == PieceType::Player;
        });
}

bool Tile::hasEnemy() const
{
    return std::any_of(
        occupants.begin(),
        occupants.end(),
        [](const GamePiece* piece)
        {
            return piece->getPieceType() == PieceType::Zombie;
        });
}

std::vector<GamePiece*> Tile::getOccupantsWithoutPlayer(const GamePiece* player) const {
    std::vector<GamePiece*> result;
    result.reserve(occupants.size());

    for (GamePiece* occupant : occupants) {
        if (occupant != player) {
            result.push_back(occupant);
        }
    }

    return result;
}
