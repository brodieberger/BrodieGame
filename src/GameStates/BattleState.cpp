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

BattleState::BattleState(
    EnemyManager& enemyManager,
    Renderer& renderer,
    ActionProcessor& actionProcessor
)
    : GameState(enemyManager, renderer),
      actionProcessor(actionProcessor)
{
    battleTurnCounter = 1;
    selectedEnemy = 0;
}

BattleState::~BattleState() {
	// TODO Auto-generated destructor stub
}

void BattleState::handleInput(int keyPressed) {
	renderer.setAlertText("Press SPACE to attack!");
	auto& enemyList = enemyManager.getEnemyList();
    for (auto& enemy : enemyList){
    	enemy->setOutlineColor(BLACK);
    }

	bool advanceTurn {false};
    if (enemyList.empty())
        return;
    if (keyPressed == KEY_RIGHT) {
        selectedEnemy = (selectedEnemy + 1) % enemyList.size();
    }
    else if (keyPressed == KEY_LEFT) {
        selectedEnemy = (selectedEnemy + enemyList.size() - 1) % enemyList.size();
    }
    if (keyPressed == KEY_SPACE && !actionProcessor.busy() ) {
    	Action action = enemyManager.getPlayer()->attack(enemyList[selectedEnemy].get());
		actionProcessor.queueActionBack(action);
		advanceTurn = true;
	}

    if(advanceTurn){
    	update();
    }
}

void BattleState::update() {
	auto& enemyList = enemyManager.getEnemyList();
	for (auto& enemy : enemyList){
		if(enemy->getIsAlive()){
	    	Action action = (enemy->attack(enemyManager.getPlayer()));
			actionProcessor.queueActionBack(action);
		}
	}
    battleTurnCounter += 1;
    incrementTurnCounter();
}

void BattleState::render() {
	auto& enemyList = enemyManager.getEnemyList();
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

	renderer.setUpperText(
		"Current Turn: " + std::to_string(battleTurnCounter)
	);
	renderer.setLevelText("BATTLING");
	renderer.drawEnemies(enemyList);
};
