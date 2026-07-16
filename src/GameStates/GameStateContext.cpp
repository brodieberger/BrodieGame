/*
 * GameStateContext.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "GameStateContext.h"


GameStateContext::GameStateContext(
    GameWorld& world,
    Renderer& renderer,
    ActionProcessor& processor)
{
    overworldState = std::make_unique<OverworldState>(
        world,
        renderer,
        *this
    );

    battleState = std::make_unique<BattleState>(
        world,
        renderer,
		*this,
		processor
    );

    state = overworldState.get();
}

void GameStateContext::update() {
	state->update();
}
void GameStateContext::render() {
	state->render();
}

void GameStateContext::enterBattle()
{
    state = battleState.get();
}

void GameStateContext::enterOverworld()
{
    state = overworldState.get();
}

void GameStateContext::handleInput(int keyPressed) {
	state->handleInput(keyPressed);
}
