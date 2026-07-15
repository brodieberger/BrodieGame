/*
 * GamePiece.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include <iostream>
#include "GamePiece.h"

GamePiece::GamePiece()
    : pieceType(PieceType::Unknown),
      m_HP(0),
      coord{0, 0}
{
}

inline std::ostream& operator<<(std::ostream& os, PieceType type)
{
	switch (type)
	{
		case PieceType::Player: return os << "Player";
		case PieceType::Zombie: return os << "Zombie";
		default: return os << "Unknown";
	}
}
