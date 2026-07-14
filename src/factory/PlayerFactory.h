/*
 * PlayerFactory.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef PLAYERFACTORY_H_
#define PLAYERFACTORY_H_
#include "GamePieceFactory.h"

class PlayerFactory : public GamePieceFactory {
public:
    std::unique_ptr<GamePiece> create(std::string name, int HP) const override;
};

#endif /* PLAYERFACTORY_H_ */
