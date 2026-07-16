/*
 * GameWorld.cpp
 *
 *  Created on: Jul 16, 2026
 *      Author: ASRCFH\bberger
 */

#include "GameWorld.h"

void GameWorld::removeDeadEnemies()
{
    auto& enemies = enemyManager.getEnemyList();
    for (auto& enemy : enemies)
    {
        if (!enemy->getIsAlive())
        {
            grid.removePiece(enemy.get());
        }
    }
    enemyManager.removeDeadEnemies();
}

void GameWorld::spawnEnemy(Coord spawnCoord){
	GamePiece* enemy = getEnemyManager().spawnEnemy(spawnCoord);
	Tile& tile = getGrid().getTileByCoords(spawnCoord);
	getGrid().movePiece(enemy, tile);
}
