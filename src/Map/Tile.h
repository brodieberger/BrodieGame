/*
 * Tile.h
 *
 *  Created on: Jul 13, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef TILE_H_
#define TILE_H_

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

private:
	int tileID;
	TileType tileType = TileType::Walkable;
	bool isOccupied = false;
};

#endif /* TILE_H_ */
