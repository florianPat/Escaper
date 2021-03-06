#pragma once

#include "Graphics.h"

class TileMap
{
	static constexpr int tilesWidth = 50, tilesHeight = 50;
	static constexpr int width = (Graphics::ScreenWidth / tilesWidth) - 4;
	static constexpr int height = Graphics::ScreenHeight / tilesHeight / 2; //12x6

	Color blankColor = Colors::Black, playerColor = Colors::Blue, enemieFrontColor = Colors::Magenta,
		coinColor = Colors::Yellow, enemieBackColor = Colors::Red;
public:
	enum class TileType { Blank, Player, EnemieFront, Coin, EnemieBack };
private:
	TileType tileMap[width*height] = { TileType::Blank };
	Color tileMapColors[width*height] = { Colors::Black };
public:
	TileMap() = default;
	void setTileTypeAtPos(TileType tileType, Vec2& pos);
	TileType getTileTypeAtpos(Vec2& pos);
	void draw(Graphics& gfx);
	void update();
	int getTileMapWith();
	int getTileMapHeight();
	void clear();
};