/*
 * Game.h
 *
 *  Created on: Jul 8, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAME_H_
#define GAME_H_
#include <memory>

#include "Renderer.h"
#include "GameStates/GameStateContext.h"
#include "GameStates/OverworldState.h"
#include "GameStates/BattleState.h"
#include "ActionProcessor.h"
#include "GameWorld.h"

class Game {
private:
    static const int MAX_ENEMIES = 5;

    std::unique_ptr<GameWorld> gameWorld;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<ActionProcessor> actionProcessor;
    std::unique_ptr<GameStateContext> gameState;

public:
    Game();
    ~Game() = default;

    void run();
};

#endif /* GAME_H_ */
