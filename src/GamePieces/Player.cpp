/*
 * Player.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include <iostream>
#include "Player.h"

Player::Player(Coord spawnCoord)
: GamePiece(spawnCoord){
	setPieceType(PieceType::Player);
	setName("Player");
	setCoord(spawnCoord);
	setHP(100);
}

Action Player::attack(GamePiece* target) {
	Action action;

	action.setOutlineColor(target, GOLD);
	action.addMessage(this, "You prepare to attack.", GOLD);
	action.addAttack(target, this, 5);
	action.setOutlineColor(target, BLACK);

	return action;
}

Action Player::receiveAttack()
{
    Action action;

    action.addReceiveAttack(this, 5);
    action.addMessage(this, "You have been attacked!\nYou have " + std::to_string(getHP() - 5) + " HP.", RED);

    return action;
}
