/*
 * Renderer.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#include "Renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer() {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Brodie's awesome game");
    SetTargetFPS(60);
}

Renderer::~Renderer() {
	CloseWindow();
}

void Renderer::clearScreen(){

}

void Renderer::renderHUD(){
    DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT-530, GRAY);

    // OUTLINE
    DrawRectangle(0, 440, WINDOW_WIDTH, WINDOW_HEIGHT-400, alertColor);
    DrawRectangle(10, 450, WINDOW_WIDTH-20, WINDOW_HEIGHT-460, GRAY);
    DrawText(upperText.c_str(), 5, 0, 30, WHITE);
    DrawText(levelText.c_str(), WINDOW_WIDTH - 170, 0, 30, WHITE);
    DrawText(alertText.c_str(), 15, 460, 30, WHITE);

}

void Renderer::drawEnemies(std::vector<std::unique_ptr<GamePiece>>& enemies) {
    const int boxSize = 195;
    const int numEnemies = enemies.size();

    if (numEnemies == 0)
        return;

    int spacing = (WINDOW_WIDTH - (numEnemies * boxSize)) / (numEnemies + 1);
    int y = 125;

    for (int i = 0; i < numEnemies; i++) {
    	if(enemies[i]->getIsAlive()){
    		int x = spacing + i * (boxSize + spacing);

    		//Draw Outline
    		Color outlineColor = enemies[i]->getOutlineColor();
			DrawRectangle(x-5, y-5, boxSize+10, boxSize+10, outlineColor);

			DrawRectangle(x, y, boxSize, boxSize, GRAY);
			DrawText(enemies[i]->getName().c_str(), x + 5, y + 5, 25, WHITE);

			std::string hpText = "HP: " + std::to_string(enemies[i]->getHP());
			DrawText(hpText.c_str(), x + 5, y + 160, 25, WHITE);
    	}
    }
}

void Renderer::renderTiles(const Grid& grid)
{
    const int tileSize = 72;
    const int startX = 50;
    const int startY = 50;

    const auto& rows = grid.getGrid();

    for (size_t y = 0; y < rows.size(); ++y)
    {
        for (size_t x = 0; x < rows[y].size(); ++x)
        {
            const Tile& tile = rows[y][x];

            int screenX = startX + x * tileSize;
            int screenY = startY + y * tileSize;

            // Draw the tile
            Color color = (tile.getTileType() == TileType::Walkable)
                ? DARKGREEN
                : DARKGRAY;

            DrawRectangle(screenX, screenY, tileSize, tileSize, color);
            DrawRectangleLines(screenX, screenY, tileSize, tileSize, BLACK);

            // Draw occupants
            if (tile.hasPlayer())
            {
                DrawCircle(
                    screenX + tileSize / 2,
                    screenY + tileSize / 2,
                    tileSize / 4,
                    BLUE);
            }

            if (tile.hasEnemy())
            {
                DrawCircle(
                    screenX + tileSize / 2,
                    screenY + tileSize / 2,
                    tileSize / 4,
                    RED);
            }

            if (tile.hasPlayer() && tile.hasEnemy())
            {
                DrawText(
                    "!",
                    screenX + tileSize / 2 - 5,
                    screenY + tileSize / 2 - 10,
                    20,
                    YELLOW);
            }
        }
    }
}
