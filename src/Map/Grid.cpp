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
            grid[row][col] = Tile(ID, {col, row});
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

Tile& Grid::getTileByCoords(Coord coord) {
    return grid.at(coord.y).at(coord.x);
}

bool Grid::isValidCoord(Coord coord) const
{
    return coord.x >= 0 && coord.x < GRIDWIDTH && coord.y >= 0 && coord.y < GRIDHEIGHT;
}

void Grid::movePiece(GamePiece* gamepiece, Tile& destinationTile)
{
    Tile& currentTile = getTileByCoords(gamepiece->getCoord());

    currentTile.removeOccupant(gamepiece);
    destinationTile.addOccupant(gamepiece);

    gamepiece->setCoord(destinationTile.getCoord());
}

void Grid::removePiece(GamePiece* piece)
{
    getTileByCoords(piece->getCoord()).removeOccupant(piece);
}
