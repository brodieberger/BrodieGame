/*
 * Tile.h
 *
 *  Created on: Jul 13, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef TILE_H_
#define TILE_H_
#include "../../GamePieces/GamePiece.h"
#include <algorithm>

enum class TileType
{
    Walkable,
	NonWalkable,
};

class Tile {
public:
	Tile();
	Tile(int newTileID, Coord newCoord);
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
	bool hasPlayer() const;
	bool hasEnemy() const;

	const std::vector<GamePiece*>& getOccupants() const {
		return occupants;
	}

	std::vector<GamePiece*> getOccupantsWithoutPlayer(const GamePiece* player) const;

	void addOccupant(GamePiece* gamePiece) {
		occupants.push_back(gamePiece);
	}
	void removeOccupant(GamePiece* gamePiece)
	{
	    auto it = std::find(occupants.begin(), occupants.end(), gamePiece);
	    if (it != occupants.end())
	        occupants.erase(it);
	}

	TileType getTileType() const {
		return tileType;
	}

	void setTileType(TileType tileType = TileType::Walkable) {
		this->tileType = tileType;
	}

	Coord getCoord() const {
		return coord;
	}

private:
    int tileID;
    Coord coord;
    TileType tileType = TileType::Walkable;
    std::vector<GamePiece*> occupants;
};

#endif /* TILE_H_ */
