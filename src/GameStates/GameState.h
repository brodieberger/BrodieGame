/*
 * GameState.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include "../Renderer.h"
#include "../EnemyManager.h"

class GameState
{
public:
    GameState(
        EnemyManager& enemyManager,
        Renderer& renderer
    )
        : enemyManager(enemyManager),
          renderer(renderer)
    {}

    virtual ~GameState() = default;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput(int keyPressed) = 0;
    int getTurnCounter(){
    	return turnCounter;
    }
    void incrementTurnCounter(){
    	turnCounter += 1;
    }

private:
    int turnCounter{1};

protected:
    EnemyManager& enemyManager;
    Renderer& renderer;
};

#endif /* GAMESTATE_H_ */
