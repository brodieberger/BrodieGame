/*
 * EnemyManager.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "EnemyManager.h"
#include <algorithm>

EnemyManager::EnemyManager()
{
    playerFactory 	= std::make_unique<PlayerFactory>();
    enemyFactory 	= std::make_unique<EnemyFactory>();
    player = playerFactory->create("Brodie", 150);

}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::update() {
    enemyList.erase(
        std::remove_if(enemyList.begin(), enemyList.end(),
            [](const std::unique_ptr<GamePiece>& enemy) {
                return enemy->getIsAlive() <= 0;
            }),
        enemyList.end());
}

void EnemyManager::spawnEnemy(std::string name, int health)
{
    auto enemy = enemyFactory->create(name, health);

    enemyList.push_back(std::move(enemy));
}
