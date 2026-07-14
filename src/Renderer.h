/*
 * Renderer.h
 *
 *  Created on: Jul 7, 2026
 *      Author: ASRCFH\bberger
 */

#ifndef RENDERER_H_
#define RENDERER_H_
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include "raylib.h"
#include "GamePieces/GamePiece.h"
#include "Action.h"
#include "Map/Grid.h"

class Renderer {
public:
	Renderer();
	virtual ~Renderer();
	void clearScreen();
	void renderHUD();
	void setUpperText(const std::string& text)
	{
	    upperText = text;
	}
	void setLowerText(const std::string& text)
	{
		lowerText = text;
	}

	void setLevelText(const std::string& text)
	{
	    levelText = text;
	}
	void setAlertText(const std::string& text){
		alertText = text;
	}
	void setAlertColor(const Color color){
		alertColor = color;
	}

	void startDisplayAlert(){
		displayingAlert = true;
	}
	void stopDisplayAlert(){
		displayingAlert = false;
	}

	void buildAlertText();
	void drawEnemies(std::vector<std::unique_ptr<GamePiece>>&);
	void drawHud();
	void renderTiles(Grid grid);

private:
	std::string upperText;
	std::string lowerText;
	std::string levelText;
	std::string alertText;

	Color alertColor = WHITE;

	double alertStartTime = 0.0;
	bool displayingAlert = false;
	static const int WINDOW_WIDTH = 1000;
	static const int WINDOW_HEIGHT = 562;
};

#endif /* RENDERER_H_ */
