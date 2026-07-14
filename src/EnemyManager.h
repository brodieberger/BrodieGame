/*
 * EnemyManager.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef ENEMYMANAGER_H_
#define ENEMYMANAGER_H_

#include <memory>
#include <vector>
#include "GamePieces/GamePiece.h"
#include "factory/EnemyFactory.h"
#include "factory/PlayerFactory.h"

class EnemyManager {
public:
    EnemyManager();
    ~EnemyManager();

    std::vector<std::unique_ptr<GamePiece>>& getEnemyList()
    {
        return enemyList;
    }
    GamePiece* getPlayer(){
    	return player.get();
    }

    void spawnEnemy(std::string name, int health);
    void update();

private:
    std::vector<std::unique_ptr<GamePiece>> enemyList;
    std::unique_ptr<EnemyFactory> enemyFactory;
    std::unique_ptr<PlayerFactory> playerFactory;
    std::unique_ptr<GamePiece> player;
};

#endif /* ENEMYMANAGER_H_ */
