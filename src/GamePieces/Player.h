/*
 * Player.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include "GamePiece.h"

class Player : public GamePiece{
public:
	Player(std::string name, int HP);
	Action attack(GamePiece* target) override;
	Action receiveAttack() override;
};

#endif /* PLAYER_H_ */
