/*
 * MenuState.cpp
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
}

OverworldState::~OverworldState() {

}

void OverworldState::update() {
	incrementTurnCounter();
};

void OverworldState::render() {
	renderer.setUpperText("Current Turn: " + std::to_string(getTurnCounter()));
	renderer.setLevelText("Overworld");
	renderer.renderTiles(grid);
};

void OverworldState::handleInput(int keyPressed) {
	render();
};

