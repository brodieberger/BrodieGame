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
	renderer.renderTiles(gameWorld.getGrid());
};

void OverworldState::handleInput(int keyPressed) {

	if (keyPressed == KEY_Z){
		createEnemy({1,1});
	}

	Tile* tileToMoveTo = handleMovement(gameWorld.getEnemyManager().getPlayer(), keyPressed);

	if (tileToMoveTo)
	{
		gameWorld.getGrid().movePiece(gameWorld.getEnemyManager().getPlayer(), *tileToMoveTo);
	    update();
	}

	gameWorld.removeDeadEnemies();
	render();
};

Tile* OverworldState::handleMovement(GamePiece* gamepiece, int keyPressed)
{
	renderer.setAlertText("Use the arrow keys to move!");
    Coord newCoord = gamepiece->getCoord();

    switch (keyPressed)
    {
        case KEY_UP:    --newCoord.y; break;
        case KEY_DOWN:  ++newCoord.y; break;
        case KEY_LEFT:  --newCoord.x; break;
        case KEY_RIGHT: ++newCoord.x; break;
    }

    if (!gameWorld.getGrid().isValidCoord(newCoord))
        return nullptr;

    Tile& newTile = gameWorld.getGrid().getTileByCoords(newCoord);

    if (newTile.getCoord().x == gamepiece->getCoord().x && newTile.getCoord().y == gamepiece->getCoord().y){
    	return nullptr;
    }

    if (newTile.getTileType() == TileType::NonWalkable)
        return nullptr;

    return &newTile;
}

void OverworldState::createEnemy(Coord spawnCoord){
	GamePiece* enemy = gameWorld.getEnemyManager().spawnEnemy(spawnCoord);
	Tile& tile = gameWorld.getGrid().getTileByCoords(spawnCoord);
	gameWorld.getGrid().movePiece(enemy, tile);
}
