/*
 * OverworldState.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef OVERWORLDSTATE_H_
#define OVERWORLDSTATE_H_
#include "GameState.h"
#include "../GamePieces/GamePiece.h"

enum class Direction{
	Right,
	Left,
	Down,
	Up,
};

class OverworldState : public GameState {
public:
	OverworldState(EnemyManager& enemyManager, Renderer& renderer);

    void update() override;
    void render() override;
    void handleInput(int keyPressed) override;
    Tile* handleMovement(GamePiece* gamepiece, Direction direction);

    void renderTiles();
    void createEnemy();

private:
    Grid grid;
};

#endif /* OVERWORLDSTATE_H_ */
