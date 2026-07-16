/*
 * EnemyManager.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "EnemyManager.h"
#include <algorithm>

EnemyManager::EnemyManager(){
    playerFactory 	= std::make_unique<PlayerFactory>();
    enemyFactory 	= std::make_unique<EnemyFactory>();
    Coord spawnCoord (0,0);
    player = playerFactory->create(spawnCoord);

}

void EnemyManager::update() {

}

void EnemyManager::removeDeadEnemies()
{
    enemyList.erase(
        std::remove_if(
            enemyList.begin(),
            enemyList.end(),
            [](const std::unique_ptr<GamePiece>& enemy)
            {
                return !enemy->getIsAlive();
            }),
        enemyList.end());
}

GamePiece* EnemyManager::spawnEnemy(Coord spawnCoord)
{
    auto enemy = enemyFactory->create(spawnCoord);
    GamePiece* ptr = enemy.get();

    enemyList.push_back(std::move(enemy));

    return ptr;
}
