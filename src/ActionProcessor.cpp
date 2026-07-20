/*
 * ActionProcessor.cpp
 *
 * Created on: Jul 10, 2026
 * Author: ASRCFH\bberger
 */

#include "ActionProcessor.h"
#include "raylib.h"
#include "Renderer.h"
#include <iostream>

ActionProcessor::ActionProcessor(Renderer& renderer)
    : renderer(renderer)
{
}

void ActionProcessor::queueActionBack(const Action& action)
{
    actions.push_back(action);
}
void ActionProcessor::queueActionFront(const Action& action)
{
    actions.push_front(action);
}

bool ActionProcessor::busy() const
{
    return processing || !actions.empty();
}

size_t ActionProcessor::queueSize() const
{
    return actions.size();
}

void ActionProcessor::update()
{
    const double currentTime = GetTime();

    // Start a new action if idle
    if (!processing)
    {
        if (actions.empty())
        {
            return;
        }

        currentAction = actions.front();
        actions.pop_front();

        currentStep = 0;
        processing = true;

        auto& steps = currentAction.getSteps();

        if (steps.empty())
        {
            processing = false;
            return;
        }

        while (currentStep < steps.size())
        {
            bool executed = executeStep(steps[currentStep]);

            currentStep++;

            if (executed)
            {
                timer = currentTime;
                stepDuration = steps[currentStep - 1].duration;
                break;
            }
        }
    }

    // Wait until the current step finishes
    if (currentTime - timer < stepDuration)
    {
        return;
    }

    timer = currentTime;

    auto& steps = currentAction.getSteps();

    // Action finished
    if (currentStep >= steps.size())
    {
        processing = false;
        stepDuration = 0.0;
        renderer.setAlertText("Press SPACE to attack");
        renderer.setAlertColor(WHITE);
        return;
    }

    // Execute next step
    while (currentStep < steps.size())
    {
        bool executed = executeStep(steps[currentStep]);

        currentStep++;

        if (executed)
        {
            timer = currentTime;
            stepDuration = steps[currentStep - 1].duration;
            break;
        }
    }
}

bool ActionProcessor::executeStep(ActionStep& step)
{
    switch (step.type)
    {
    case ActionStepType::Message:
    	if (step.initiator != nullptr && step.initiator->getIsAlive() == true)
    	{
			renderer.setAlertText(step.text);
			renderer.setAlertColor(step.color);
			return true;
    	}
    	return false;

    case ActionStepType::DeathMessage:
    	renderer.setAlertText(step.text);
		renderer.setAlertColor(step.color);
		return true;

    case ActionStepType::Attack:
		if (step.target != nullptr && step.initiator->getIsAlive() == true)
		{
			queueActionFront(step.target->receiveAttack());
			return true;
		}
		return false;

    case ActionStepType::ReceiveAttack:
        if (step.target != nullptr)
        {
            step.target->setHP(
                step.target->getHP() - step.damage
            );
            return true;
        }
        return false;

    case ActionStepType::SetOutlineColor:
    	if (step.target != nullptr)
		{
    		step.target->setOutlineColor(step.color);
    		return true;
		}
    	return false;

    case ActionStepType::CompleteTurn:
    {
        GameState* gamestate = step.gamestate;
        if (gamestate)
            gamestate->update();
        return true;
    }

    default:
        return false;
    }
}
