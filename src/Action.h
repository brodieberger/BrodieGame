/*
 * Action.h
 *
 *  Created on: Jul 9, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMEPIECES_ACTION_H_
#define GAMEPIECES_ACTION_H_
#include <string>
#include <vector>
#include "raylib.h"
#include "GameStates/GameState.h"

class GamePiece;

enum class ActionStepType
{
    Message,
	DeathMessage,
	SetOutlineColor,
	Attack,
    ReceiveAttack,
	CompleteTurn,
};

struct ActionStep
{
    ActionStepType type;

    std::string text;
    int damage = 0;
    double duration = 0;
    Color color;

    GameState* gamestate;
    GamePiece* initiator;
    GamePiece* target;
};

class Action
{
public:
    Action() = default;

    void addMessage(GamePiece* initiator, std::string newText, Color color);
    void addDeathMessage(std::string newText, Color color);
    void setOutlineColor(GamePiece* target, Color color);
    void addReceiveAttack(GamePiece* target, int damage);
    void addAttack(GamePiece* target, GamePiece* initiator, int damage);
    void addDelay(double duration);
    void completeTurn(GameState* gamestate);

    std::vector<ActionStep>& getSteps(){
        return steps;
    }

private:
    std::vector<ActionStep> steps;
};


#endif /* GAMEPIECES_ACTION_H_ */
