/*
 * ZombieFactory.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef FACTORY_ENEMYFACTORY_H_
#define FACTORY_ENEMYFACTORY_H_
#include "GamePieceFactory.h"

class EnemyFactory : public GamePieceFactory {
public:
    std::unique_ptr<GamePiece> create(std::string name, int HP) const override;
};


#endif /* FACTORY_ENEMYFACTORY_H_ */
