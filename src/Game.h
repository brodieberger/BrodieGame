/*
 * Game.h
 *
 *  Created on: Jul 8, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAME_H_
#define GAME_H_
#include <memory>

#include "EnemyManager.h"
#include "Renderer.h"
#include "GameStates/GameStateContext.h"
#include "GameStates/OverworldState.h"
#include "GameStates/BattleState.h"
#include "ActionProcessor.h"

class Game {
private:
    static const int MAX_ENEMIES = 5;

    std::unique_ptr<EnemyManager> enemyManager;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<ActionProcessor> actionProcessor;
    GameStateContext gameState;

    std::unique_ptr<OverworldState> overworldState;
    std::unique_ptr<BattleState> battleState;


public:
    Game();
    ~Game() = default;

    void run();
    void handleInput();
};

#endif /* GAME_H_ */
