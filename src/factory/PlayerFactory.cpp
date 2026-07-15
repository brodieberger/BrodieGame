/*
 * PlayerFactory.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include <iostream>
#include "PlayerFactory.h"
#include "../GamePieces/Player.h"
#include "EnemyFactory.h"

std::unique_ptr<GamePiece> PlayerFactory::create() const {
    return std::make_unique<Player>();
}
