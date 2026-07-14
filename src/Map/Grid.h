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
	virtual ~Grid();
	void printGrid();

private:
	std::vector<std::vector<Tile>> grid;
	static const int GRIDWIDTH = 5;
	static const int GRIDHEIGHT = 5;
};

#endif /* GRID_H_ */
