/*
 * GamePiece.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */
#include <string>
#include "../Action.h"

#ifndef GAMEPIECE_H_
#define GAMEPIECE_H_

class Coord{
private:
	int x;
	int y;
};

class GamePiece{
private:
	std::string m_Name;
	int m_HP;
	Coord coord;
	bool isAlive {true};
	Color outlineColor = BLACK;

public:
    GamePiece(std::string name, int HP);
	virtual ~GamePiece() = default;
	virtual Action attack(GamePiece* target) = 0;
	virtual Action receiveAttack() = 0;

	std::string getName() const{
		return m_Name;
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
};
std::ostream& operator<<(std::ostream& os, const GamePiece& p);

#endif /* GAMEPIECE_H_ */
