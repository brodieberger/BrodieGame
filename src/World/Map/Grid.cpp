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

Tile* Grid::handleMovement(GamePiece* gamepiece, int keyPressed)
{
    Coord newCoord = gamepiece->getCoord();

    switch (keyPressed)
    {
        case KEY_UP:    --newCoord.y; break;
        case KEY_DOWN:  ++newCoord.y; break;
        case KEY_LEFT:  --newCoord.x; break;
        case KEY_RIGHT: ++newCoord.x; break;
    }

    if (!isValidCoord(newCoord))
        return nullptr;

    Tile& newTile = getTileByCoords(newCoord);

    if (newTile.getCoord().x == gamepiece->getCoord().x && newTile.getCoord().y == gamepiece->getCoord().y){
    	return nullptr;
    }

    if (newTile.getTileType() == TileType::NonWalkable)
        return nullptr;

    return &newTile;
}

Tile* Grid::checkForCombat()
{
    for (auto& row : grid)
    {
        for (auto& tile : row)
        {
            if (tile.hasPlayer() && tile.hasEnemy())
            {
                return &tile;
            }
        }
    }

    return nullptr;
}

void Grid::printGrid()
{
	std::cout << "\n\n\n";
    for (const auto& row : grid)
    {
        for (const auto& tile : row)
        {
            if (tile.hasPlayer() && tile.hasEnemy())
            {
                std::cout << "! ";
            }
            else if (tile.hasPlayer())
            {
                std::cout << "P ";
            }
            else if (tile.hasEnemy())
            {
                std::cout << "E ";
            }
            else if (tile.getTileType() == TileType::NonWalkable)
            {
                std::cout << "# ";
            }
            else
            {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
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
