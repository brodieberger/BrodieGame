/*
 * Zombie.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include <iostream>
#include "Zombie.h"

Zombie::Zombie(std::string name, int HP)
    : GamePiece(name, HP) {
	std::cout << "zombie spawned\n";
}

Action Zombie::attack(GamePiece* target)
{
    Action action;

    action.setOutlineColor(this, RED);
    action.addMessage(this, "Zombie prepares to attack.", RED);
	action.addAttack(target, this, 5);
	action.setOutlineColor(this, BLACK);

    return action;
}

Action Zombie::receiveAttack()
{
    Action action;

	action.addReceiveAttack(this, 5, GOLD);

    if ((getHP()-5) > 0){
        action.addMessage(this, getName() + " has been attacked!\n5 Damage Dealt.", GOLD);
    }
    else{
    	action.addDeathMessage(getName() + " has been slain!", GOLD);
    	killPiece();
    }

    return action;
}
