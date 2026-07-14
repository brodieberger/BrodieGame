/*
 * ActionProcessor.h
 *
 *  Created on: Jul 10, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef ACTIONPROCESSOR_H_
#define ACTIONPROCESSOR_H_

#include <queue>
#include "Action.h"

class Renderer;

class ActionProcessor
{
public:
    ActionProcessor(Renderer& renderer);

    void queueActionFront(const Action& action);
    void queueActionBack(const Action& action);
    bool executeStep(ActionStep& step);
    size_t queueSize() const;
    void update();
    bool busy() const;

private:
    Renderer& renderer;

    std::deque<Action> actions;

    Action currentAction;
    size_t currentStep = 0;
    double stepDuration = 0;

    bool processing = false;
    double timer = 0.0;
};

#endif
