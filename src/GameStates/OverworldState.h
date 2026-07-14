/*
 * MenuState.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef OVERWORLDSTATE_H_
#define OVERWORLDSTATE_H_
#include "GameState.h"

class OverworldState : public GameState {
public:
	OverworldState(EnemyManager& enemyManager, Renderer& renderer);
	virtual ~OverworldState();

    void update() override;
    void render() override;
    void handleInput(int keyPressed) override;

    void renderTiles();

private:
    Grid grid;
};

#endif /* OVERWORLDSTATE_H_ */
