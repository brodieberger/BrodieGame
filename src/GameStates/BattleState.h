/*
 * BattleState.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef BATTLESTATE_H_
#define BATTLESTATE_H_
#include "GameState.h"
#include <vector>
#include <memory>
#include "../GamePieces/GamePiece.h"
#include "../ActionProcessor.h"


class BattleState : public GameState {
public:
	BattleState(GameWorld& gameWorld, Renderer& renderer, GameStateContext& gameStateContext, ActionProcessor& actionProcessor);
	virtual ~BattleState();

    void update() override;
    void render() override;
    void handleInput(int keyPressed) override;

    int getBattleTurnCounter() const {
    	return battleTurnCounter;
    }

private:
	int battleTurnCounter;
	size_t selectedEnemy;
	std::vector<std::unique_ptr<GamePiece>> combatantList;
    ActionProcessor& actionProcessor;
};

#endif /* BATTLESTATE_H_ */
