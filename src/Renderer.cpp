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

// TODO MAKE THIS RENDER
void Renderer::renderTiles(Grid& grid){


	grid.printGrid();
}
