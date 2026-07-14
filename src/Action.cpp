/*
 * Action.cpp
 *
 *  Created on: Jul 9, 2026
 *      Author: ASRCFH\bberger
 */

#include <string>
#include <iostream>
#include "Action.h"
#include "GamePieces/GamePiece.h"



void Action::addMessage(GamePiece* initiator, std::string text, Color color)
{
    ActionStep step;

    step.type = ActionStepType::Message;
    step.text = std::move(text);
    step.initiator = initiator;
    step.duration = 1.0;
    step.color = color;

    steps.push_back(step);
}

void Action::addDeathMessage(std::string text, Color color)
{
    ActionStep step;

    step.type = ActionStepType::DeathMessage;
    step.text = std::move(text);
    step.initiator = nullptr;
    step.duration = 1.0;
    step.color = color;

    steps.push_back(step);
}

void Action::setOutlineColor(GamePiece* target, Color color)
{
    ActionStep step;

    step.type = ActionStepType::SetOutlineColor;
    step.initiator = nullptr;
    step.target = target;
    step.duration = 0;
    step.color = color;

    steps.push_back(step);
}

void Action::addAttack(GamePiece* target, GamePiece* initiator, int damage)
{
    ActionStep step;

    step.type = ActionStepType::Attack;
    step.target = target;
    step.initiator = initiator;
    step.damage = damage;
    step.duration = 0;

    steps.push_back(step);
}


void Action::addReceiveAttack(GamePiece* target, int damage, Color color)
{
    ActionStep step;

    step.type = ActionStepType::ReceiveAttack;
    step.target = target;
    step.damage = damage;
    step.duration = 0;
    step.color = color;

    steps.push_back(step);
}
