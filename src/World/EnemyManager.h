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
#include "../GamePieces/GamePiece.h"
#include "../GamePieces/factory/EnemyFactory.h"
#include "../GamePieces/factory/PlayerFactory.h"

class EnemyManager {
public:
    EnemyManager();
    ~EnemyManager() = default;

    std::vector<std::unique_ptr<GamePiece>>& getEnemyList()
    {
        return enemyList;
    }
    GamePiece* getPlayer(){
    	return player.get();
    }
    void removeDeadEnemies();
    GamePiece* spawnEnemy(Coord spawnCoord);
    void update();

private:
    std::vector<std::unique_ptr<GamePiece>> enemyList;
    std::unique_ptr<EnemyFactory> enemyFactory;
    std::unique_ptr<PlayerFactory> playerFactory;
    std::unique_ptr<GamePiece> player;
};

#endif /* ENEMYMANAGER_H_ */
