/*
 * GameWorld.h
 *
 *  Created on: Jul 16, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_
#include "World/EnemyManager.h"
#include "World/Map/Grid.h"


class GameWorld {
public:
	EnemyManager& getEnemyManager()
	{
	    return enemyManager;
	}

	Grid& getGrid() {
	    return grid;
	}

	void removeDeadEnemies();
	void spawnEnemy(Coord spawnCoord);

	int getTurnCounter() const {
		return turnCounter;
	}

	void incrementTurnCounter() {
		turnCounter++;
	}

private:
	EnemyManager enemyManager;
	Grid grid;
	int turnCounter;
};

#endif /* GAMEWORLD_H_ */
