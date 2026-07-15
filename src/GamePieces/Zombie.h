/*
 * Zombie.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#include <string>
#include "GamePiece.h"

class Zombie : public GamePiece{
public:
	Zombie();
	Action attack(GamePiece* target) override;
	Action receiveAttack() override;
};

#endif /* ZOMBIE_H_ */
