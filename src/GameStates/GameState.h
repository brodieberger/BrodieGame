/*
 * GameState.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameWorld;
class Renderer;
class GameStateContext;

class GameState
{
public:
    GameState(
        GameWorld& gameWorld,
        Renderer& renderer,
        GameStateContext& context
    )
        : gameWorld(gameWorld),
          renderer(renderer),
          stateContext(context)
    {}

    virtual ~GameState() = default;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput(int keyPressed) = 0;

protected:
    GameWorld& gameWorld;
    Renderer& renderer;
    GameStateContext& stateContext;
};

#endif /* GAMESTATE_H_ */
