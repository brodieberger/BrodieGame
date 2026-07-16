/*
 * EnemyFactory.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#include <memory>
#include "../Zombie.h"
#include "EnemyFactory.h"

// Use this to spawn multiple types. If the zombie limit is reached spawn skeletons or something

std::unique_ptr<GamePiece> EnemyFactory::create(Coord spawnCoord) const {
    return std::make_unique<Zombie>(spawnCoord);
}
