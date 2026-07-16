/*
 * EnemyFactory.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef FACTORY_ENEMYFACTORY_H_
#define FACTORY_ENEMYFACTORY_H_
#include "GamePieceFactory.h"

class EnemyFactory : public GamePieceFactory {
public:
    std::unique_ptr<GamePiece> create(Coord spawnCoord) const override;
};

#endif /* FACTORY_ENEMYFACTORY_H_ */
