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
    GameStateContext& context
)
    : GameState(gameWorld, renderer, context)
{
	//DEBUG SPAWN
	createEnemy({3,3});

    Tile& tile = gameWorld.getGrid().getTileByCoords(gameWorld.getEnemyManager().getPlayer()->getCoord());
    gameWorld.getGrid().movePiece(gameWorld.getEnemyManager().getPlayer(), tile);

    gameWorld.getGrid().getTileByCoords({5,2}).setTileType(TileType::NonWalkable);
    gameWorld.getGrid().getTileByCoords({5,3}).setTileType(TileType::NonWalkable);
    gameWorld.getGrid().getTileByCoords({6,2}).setTileType(TileType::NonWalkable);
    gameWorld.getGrid().getTileByCoords({6,3}).setTileType(TileType::NonWalkable);
}

void OverworldState::update() {
	//TODO for each enemy. Run their overworld update function.


	if (gameWorld.getGrid().checkForCombat())
	{
	    stateContext.enterBattle();
	}
};

void OverworldState::render() {
	renderer.setUpperText("Current Turn: " + std::to_string(gameWorld.getTurnCounter()));
	renderer.setLevelText("Overworld");
	renderer.setAlertText("Use the arrow keys to move!");
	renderer.renderTiles(gameWorld.getGrid());
};

void OverworldState::handleInput(int keyPressed) {

	if (keyPressed == KEY_Z){
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
