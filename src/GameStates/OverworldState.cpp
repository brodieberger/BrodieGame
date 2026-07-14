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
	auto& actualGrid = grid.getGrid();
	actualGrid[2][2].addOccupants(enemyManager.getPlayer());

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
	update();
	render();

};

