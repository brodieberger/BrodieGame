/*
 * BattleState.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "BattleState.h"

#include <iostream>
#include <string>
#include "raylib.h"
#include "../Action.h"
#include "BattleState.h"
#include "../GameWorld.h"
#include "../Renderer.h"
#include "../GameStates/GameStateContext.h"

BattleState::BattleState(
    GameWorld& gameWorld,
    Renderer& renderer,
    GameStateContext& context,
    ActionProcessor& actionProcessor
)
    : GameState(gameWorld, renderer, context, actionProcessor),
      battleTurnCounter(1),
      selectedEnemy(0)
{
}

BattleState::~BattleState() {
	// TODO Auto-generated destructor stub
}

void BattleState::handleInput(int keyPressed) {

	gameWorld.removeDeadEnemies();

	if (actionProcessor.busy()){
		return;
	}

	renderer.setAlertText("Press SPACE to attack!");
	GamePiece* player = gameWorld.getEnemyManager().getPlayer();
    Grid& grid = gameWorld.getGrid();
    Tile& combatTile = grid.getTileByCoords(player->getCoord());

    auto enemyList = combatTile.getOccupantsWithoutPlayer(player);
    for (auto& enemy : enemyList){
    	enemy->setOutlineColor(BLACK);
    }

	bool advanceTurn {false};
    if (enemyList.empty()){
    	stateContext.enterOverworld();
    	return;
    }


    if (keyPressed == KEY_RIGHT) {
        selectedEnemy = (selectedEnemy + 1) % enemyList.size();
    }
    else if (keyPressed == KEY_LEFT) {
        selectedEnemy = (selectedEnemy + enemyList.size() - 1) % enemyList.size();
    }
    if (keyPressed == KEY_SPACE ) {
    	Action action = gameWorld.getEnemyManager().getPlayer()->attack(enemyList[selectedEnemy]);
		actionProcessor.queueActionBack(action);
		advanceTurn = true;
	}

    if(advanceTurn){
    	update();
    }
}

void BattleState::update() {

	GamePiece* player = gameWorld.getEnemyManager().getPlayer();
    Grid& grid = gameWorld.getGrid();
    Tile& combatTile = grid.getTileByCoords(player->getCoord());
    auto enemyList = combatTile.getOccupantsWithoutPlayer(player);

	for (auto& enemy : enemyList){
		if(enemy->getIsAlive()){
	    	Action action = (enemy->attack(player));
			actionProcessor.queueActionBack(action);
		}
	}

	Action updateGameworld;
	updateGameworld.completeTurn(stateContext.getOverworldState().get());
	actionProcessor.queueActionBack(updateGameworld);
}

void BattleState::render() {
	renderer.renderTiles(gameWorld.getGrid(), gameWorld.getEnemyManager().getPlayer());
	GamePiece* player = gameWorld.getEnemyManager().getPlayer();
    Grid& grid = gameWorld.getGrid();
    Tile& combatTile = grid.getTileByCoords(player->getCoord());
    auto enemyList = combatTile.getOccupantsWithoutPlayer(player);

    if (enemyList.empty()) {
        selectedEnemy = 0;
    }
    else {
        if (selectedEnemy >= enemyList.size()) {
            selectedEnemy = enemyList.size() - 1;
        }
        if (!actionProcessor.busy()){
        	enemyList[selectedEnemy]->setOutlineColor(GOLD);
        }
    }
	renderer.setUpperText("Current Turn: " + std::to_string(gameWorld.getTurnCounter()));
	renderer.setLevelText("BATTLING");
	renderer.drawEnemies(enemyList);
};
