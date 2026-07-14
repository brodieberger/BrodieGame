/*
 * GamePieceFactory.h
 *
 *  Created on: Jul 6, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef GAMEPIECEFACTORY_H_
#define GAMEPIECEFACTORY_H_
#include <memory>
#include "../GamePieces/GamePiece.h"

class GamePieceFactory {
public:
    virtual std::unique_ptr<GamePiece> create(std::string name, int HP) const = 0;
    virtual ~GamePieceFactory() = default;
};

#endif /* GAMEPIECEFACTORY_H_ */
