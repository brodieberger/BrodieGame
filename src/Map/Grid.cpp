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

void Grid::printGrid(){
	for (std::vector<Tile> row : grid){
		for (Tile tile : row){
			if (tile.isOccupied()){
				std::cout << "1 ";
			}
			else{
				std::cout << "0 ";
			}

		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
