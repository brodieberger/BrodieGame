/*
 * ZombieFactory.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#include <string>
#include <memory>
#include <iostream>
#include "../GamePieces/Zombie.h"
#include "EnemyFactory.h"

// Eventually rename this to be enemy factory
// Use this to spawn multiple types. If the zombie limit is reached spawn skeletons or something

std::unique_ptr<GamePiece> EnemyFactory::create(std::string name, int HP) const {
    return std::make_unique<Zombie>(name, HP);
}
