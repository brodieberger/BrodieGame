/*
 * Grid.cpp
 *
 *  Created on: Jul 13, 2026
 *      Author: ASRCFH\bberger
 */

#include "Grid.h"
#include <iostream>

Grid::Grid()
    : grid(GRIDHEIGHT, std::vector<Tile>(GRIDWIDTH))
{
	int ID = 0;

    for (int row = 0; row < GRIDHEIGHT; row++) {
        for (int col = 0; col < GRIDWIDTH; col++) {
            grid[row][col] = Tile(ID);
            ID++;
        }
    }
}

Grid::~Grid() {
	// TODO Auto-generated destructor stub
}


void Grid::printGrid(){
	for (std::vector<Tile> row : grid){
		for (Tile element : row){
			std::cout << element.getTileId() << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
