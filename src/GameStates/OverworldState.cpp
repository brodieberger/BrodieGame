/*
 * OverworldState.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "OverworldState.h"
#include <iostream>

OverworldState::OverworldState(
		EnemyManager& enemyManager,
		Renderer& renderer
)
	: GameState(enemyManager, renderer)
{
	renderer.setAlertText("Use the arrow keys to move!");
	renderer.renderTiles(grid);
	createEnemy();
}

void OverworldState::update() {

	//TODO for each enemy. Run their overworld update function.

	renderer.renderTiles(grid);
	incrementTurnCounter();
};

void OverworldState::render() {
	renderer.setUpperText("Current Turn: " + std::to_string(getTurnCounter()));
	renderer.setLevelText("Overworld");
};

void OverworldState::handleInput(int keyPressed) {
	keyPressed = keyPressed - 262; //Convert to enum in header file.
	Direction direction = static_cast<Direction>(keyPressed);

	Tile* tileToMoveTo = handleMovement(enemyManager.getPlayer(), direction);

	if (tileToMoveTo)
	{
	    grid.movePiece(enemyManager.getPlayer(), *tileToMoveTo);
	    update();
	}

	for (auto& enemy : enemyManager.getEnemyList())
	{
	    if (!enemy->getIsAlive())
	    {
	        grid.removePiece(enemy.get());
	    }
	}

	enemyManager.removeDeadEnemies();
	render();
};

Tile* OverworldState::handleMovement(GamePiece* gamepiece, Direction direction)
{
    Coord newCoord = gamepiece->getCoord();

    switch (direction)
    {
        case Direction::Up:    --newCoord.y; break;
        case Direction::Down:  ++newCoord.y; break;
        case Direction::Left:  --newCoord.x; break;
        case Direction::Right: ++newCoord.x; break;
    }

    if (!grid.isValidCoord(newCoord))
        return nullptr;

    Tile& newTile = grid.getTileByCoords(newCoord);

    if (newTile.getTileType() == TileType::NonWalkable)
        return nullptr;

    return &newTile;
}

void OverworldState::createEnemy(){
	GamePiece* enemy = enemyManager.spawnEnemy();
	Tile& tile = grid.getTileByCoords(enemy->getCoord());
	grid.movePiece(enemy, tile);
}
