/*
 * Tile.h
 *
 *  Created on: Jul 13, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef TILE_H_
#define TILE_H_
#include "../GamePieces/GamePiece.h"

enum class TileType
{
    Walkable,
	NonWalkable,
};

class Tile {
public:
	Tile();
	Tile(int newTileID);
	virtual ~Tile();

	int getTileId() const {
		return tileID;
	}
	void setTileId(int tileId) {
		tileID = tileId;
	}
	const bool isOccupied() const{
		return !occupants.empty();
	}
	const std::vector<GamePiece*>& getOccupants() const {
		return occupants;
	}
	void addOccupants(GamePiece* gamePiece) {
		return occupants.emplace_back(gamePiece);
	}

private:
	int tileID;
	TileType tileType = TileType::Walkable;
	std::vector<GamePiece*> occupants;
};

#endif /* TILE_H_ */
