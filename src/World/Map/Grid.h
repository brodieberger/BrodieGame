/*
 * Grid.h
 *
 *  Created on: Jul 13, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GRID_H_
#define GRID_H_
#include <vector>
#include "Tile.h"

class Grid {
public:
	Grid();
	void printGrid();
	const std::vector<std::vector<Tile> >& getGrid() const {
		return grid;
	}

	std::vector<std::vector<Tile> >& getGrid() {
		return grid;
	}
	Tile& getTileByCoords(Coord);
	void movePiece(GamePiece* gamepiece, Tile& destination);
	void removePiece(GamePiece* piece);
	bool isValidCoord(Coord coord) const;
	Tile* checkForCombat();

private:
	std::vector<std::vector<Tile>> grid;
	static const int GRIDWIDTH = 12;
	static const int GRIDHEIGHT = 5;
};

#endif /* GRID_H_ */
