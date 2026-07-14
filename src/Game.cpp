/*
 * Game.cpp
 *
 *  Created on: Jul 8, 2026
 *      Author: ASRCFH\bberger
 */

#include "Game.h"
#include "raylib.h"
#include <iostream>


Game::Game()
{
    enemyManager = std::make_unique<EnemyManager>();

    renderer = std::make_unique<Renderer>();

    actionProcessor = std::make_unique<ActionProcessor>(
        *renderer
    );

    overworldState = std::make_unique<OverworldState>(
        *enemyManager,
        *renderer
    );

    battleState = std::make_unique<BattleState>(
        *enemyManager,
        *renderer,
        *actionProcessor
    );

    gameState.setState(overworldState.get());
}


void Game::run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        handleInput();

        gameState.render();
        renderer->renderHUD();
        enemyManager->update();
        actionProcessor->update();

        EndDrawing();
    }
}


void Game::handleInput()
{
    int keyPressed = GetKeyPressed();

    if (IsKeyPressed(KEY_B)) {
        gameState.setState(battleState.get());
    }

    if (IsKeyPressed(KEY_O)) {
        gameState.setState(overworldState.get());
    }

    if (IsKeyPressed(KEY_Z)) {

        if (enemyManager->getEnemyList().size() < MAX_ENEMIES) {
            enemyManager->spawnEnemy("Zombie", 10);
        }
        else {
            std::cout << "Enemy List full!\n";
        }
    }

    if (keyPressed != 0) {
        gameState.handleInput(keyPressed);
    }
}
