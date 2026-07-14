/*
 * GameStateContext.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMESTATES_GAMESTATECONTEXT_H_
#define GAMESTATES_GAMESTATECONTEXT_H_
#include "GameState.h"

class GameStateContext {
public:
	virtual ~GameStateContext() {}
	void setState(GameState* state);
    virtual void update();
    virtual void render();
    virtual void handleInput(int keyPressed);


private:
	GameState* state;
};
#endif /* GAMESTATES_GAMESTATECONTEXT_H_ */
