/*
 * OverworldState.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "OverworldState.h"
#include <iostream>
#include "OverworldState.h"
#include "../GameWorld.h"
#include "../Renderer.h"
#include "../GameStates/GameStateContext.h"


OverworldState::OverworldState(
    GameWorld& gameWorld,
    Renderer& renderer,
    GameStateContext& context,
	ActionProcessor& actionProcessor
)
    : GameState(gameWorld, renderer, context, actionProcessor)
{
	//DEBUG SPAWN
	createEnemy({3,3});

    Tile& tile = gameWorld.getGrid().getTileByCoords(gameWorld.getEnemyManager().getPlayer()->getCoord());
    gameWorld.getGrid().movePiece(gameWorld.getEnemyManager().getPlayer(), tile);

    /*
    gameWorld.getGrid().getTileByCoords({5,2}).setTileType(TileType::NonWalkable);
    gameWorld.getGrid().getTileByCoords({5,3}).setTileType(TileType::NonWalkable);
    gameWorld.getGrid().getTileByCoords({6,2}).setTileType(TileType::NonWalkable);
    gameWorld.getGrid().getTileByCoords({6,3}).setTileType(TileType::NonWalkable);
    */
}

void OverworldState::update()
{
    Grid& grid = gameWorld.getGrid();
    auto& enemyList = gameWorld.getEnemyManager().getEnemyList();

    GamePiece* player = gameWorld.getEnemyManager().getPlayer();

    Coord playerPos = player->getCoord();

    for (auto& enemy : enemyList)
    {
        Coord enemyPos = enemy->getCoord();

        int direction = 0;

        if (playerPos.x < enemyPos.x && playerPos.y < enemyPos.y) {
            direction = (rand() % 2 == 0) ? KEY_LEFT : KEY_UP;
        }
        else if (playerPos.x > enemyPos.x && playerPos.y < enemyPos.y) {
            direction = (rand() % 2 == 0) ? KEY_RIGHT : KEY_UP;
        }
        else if (playerPos.x < enemyPos.x && playerPos.y > enemyPos.y) {
            direction = (rand() % 2 == 0) ? KEY_LEFT : KEY_DOWN;
        }
        else if (playerPos.x > enemyPos.x && playerPos.y > enemyPos.y) {
            direction = (rand() % 2 == 0) ? KEY_RIGHT : KEY_DOWN;
        }
        else if (playerPos.x < enemyPos.x) {
            direction = KEY_LEFT;
        }
        else if (playerPos.x > enemyPos.x) {
            direction = KEY_RIGHT;
        }
        else if (playerPos.y < enemyPos.y) {
            direction = KEY_UP;
        }
        else if (playerPos.y > enemyPos.y) {
            direction = KEY_DOWN;
        }
        else {
            continue;
        }

        Tile* tileToMoveTo = grid.handleMovement(enemy.get(), direction);

        if (tileToMoveTo)
        {
            grid.movePiece(enemy.get(), *tileToMoveTo);
        }
    }

    if (grid.checkForCombat())
    {
        stateContext.enterBattle();
    }
	gameWorld.incrementTurnCounter();
}

void OverworldState::render() {
	renderer.setUpperText("Current Turn: " + std::to_string(gameWorld.getTurnCounter()));
	renderer.setLevelText("Overworld");
	renderer.setAlertText("Use the arrow keys to move!");
	renderer.renderTiles(gameWorld.getGrid(), gameWorld.getEnemyManager().getPlayer());
};

void OverworldState::handleInput(int keyPressed) {

	if (keyPressed == KEY_Z && gameWorld.getEnemyManager().getEnemyList().size() <= 5){
		createEnemy({1,1});
	}

	GamePiece* player = gameWorld.getEnemyManager().getPlayer();
	Tile* tileToMoveTo = gameWorld.getGrid().handleMovement(player, keyPressed);

	if (tileToMoveTo)
	{
		gameWorld.getGrid().movePiece(player, *tileToMoveTo);
	    update();
	}

	gameWorld.removeDeadEnemies();
	render();
};

void OverworldState::createEnemy(Coord spawnCoord){
	GamePiece* enemy = gameWorld.getEnemyManager().spawnEnemy(spawnCoord);
	Tile& tile = gameWorld.getGrid().getTileByCoords(spawnCoord);
	gameWorld.getGrid().movePiece(enemy, tile);
}
