/*
 * GamePiece.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include <iostream>
#include "GamePiece.h"

GamePiece::GamePiece(std::string name, int HP)
	: m_Name{name}, m_HP{HP} {} // @suppress("Symbol is not resolved")

std::ostream& operator<<(std::ostream& os, const GamePiece& p) {
    os << "test";
    return os;
}
