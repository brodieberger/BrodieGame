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
    gameWorld = std::make_unique<GameWorld>();
    renderer = std::make_unique<Renderer>();

    actionProcessor = std::make_unique<ActionProcessor>(
        *renderer
    );

    gameState = std::make_unique<GameStateContext>(
        *gameWorld,
        *renderer,
        *actionProcessor
    );
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        gameState->handleInput(GetKeyPressed());
        gameState->render();
        renderer->renderHUD();
        actionProcessor->update();

        EndDrawing();
    }
}

