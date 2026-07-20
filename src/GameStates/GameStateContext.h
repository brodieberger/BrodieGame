/*
 * GameStateContext.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

/*
 * GameStateContext.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMESTATES_GAMESTATECONTEXT_H_
#define GAMESTATES_GAMESTATECONTEXT_H_

#include <memory>
#include "GameState.h"
#include "OverworldState.h"
#include "BattleState.h"

class OverworldState;
class BattleState;

class GameStateContext {
public:
    GameStateContext(
        GameWorld& gameWorld,
        Renderer& renderer,
        ActionProcessor& actionProcessor
    );

    ~GameStateContext() = default;

    void enterBattle();
    void enterOverworld();

    void update();
    void render();
    void handleInput(int keyPressed);

	const std::unique_ptr<OverworldState>& getOverworldState() const {
		return overworldState;
	}

private:
    std::unique_ptr<OverworldState> overworldState;
    std::unique_ptr<BattleState> battleState;

    GameState* state = nullptr;
};

#endif
