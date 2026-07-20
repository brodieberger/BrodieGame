/*
 * OverworldState.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef OVERWORLDSTATE_H_
#define OVERWORLDSTATE_H_
#include "GameState.h"
#include "GameStateContext.h"
#include "../GamePieces/GamePiece.h"
#include "../World/Map/Tile.h"
#include "../ActionProcessor.h"


class OverworldState : public GameState {
public:
	OverworldState(GameWorld& gameWorld, Renderer& renderer, GameStateContext& gameStateContext, ActionProcessor& actionProcessor);

    void update() override;
    void render() override;
    void handleInput(int keyPressed) override;
    Tile* handleMovement(GamePiece* gamepiece, int keyPressed);

    void renderTiles();
    void createEnemy(Coord spawnCoord);

};

#endif /* OVERWORLDSTATE_H_ */
