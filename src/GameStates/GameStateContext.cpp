/*
 * GameStateContext.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "GameStateContext.h"

void GameStateContext::setState(GameState* state) {
	this->state = state;
}
void GameStateContext::update() {
	state->update();
}
void GameStateContext::render() {
	state->render();
}

void GameStateContext::handleInput(int keyPressed) {
	state->handleInput(keyPressed);
}
