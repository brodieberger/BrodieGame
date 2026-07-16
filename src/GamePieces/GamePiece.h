/*
 * GamePiece.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include <array>
#include "../Action.h"

#ifndef GAMEPIECE_H_
#define GAMEPIECE_H_

enum class PieceType{
	Unknown,
	Player,
	Zombie,
};

struct Coord{
	int x;
	int y;
	Coord(int x, int y) : x(x), y(y) {}
};

class GamePiece{
private:
	PieceType pieceType;
	std::string name;
	int m_HP;
	Coord coord;
	bool isAlive {true};
	Color outlineColor = BLACK;

public:
    GamePiece(Coord spawnCoord);
	virtual ~GamePiece() = default;
	virtual Action attack(GamePiece* target) = 0;
	virtual Action receiveAttack() = 0;

	PieceType getPieceType() const{
		return pieceType;
	}
	void setPieceType(PieceType pieceType) {
		this->pieceType = pieceType;
	}
	int getHP() const{
		return m_HP;
	}
	void setHP(int newHP) {
		m_HP = newHP;
	}
	bool getIsAlive() const{
		return isAlive;
	}
	void killPiece(){
		isAlive = false;
	}
	Color getOutlineColor() const{
		return outlineColor;
	}
	void setOutlineColor(Color color){
		outlineColor = color;
	}
	Coord getCoord() const {
		return coord;
	}
	void setCoord(Coord coord) {
		this->coord = coord;
	}
	const std::string& getName() const {
		return name;
	}
	void setName(const std::string &name) {
		this->name = name;
	}
};
std::ostream& operator<<(std::ostream& os, const GamePiece& p);

#endif /* GAMEPIECE_H_ */
