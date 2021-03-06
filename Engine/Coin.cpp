#include "Coin.h"

Coin::Coin(TileMap& tileMap, Player& player, UpdateFrequency& uf) : tileMap(tileMap), player(player), uf(uf),
			rng(), dist(0, tileMap.getTileMapHeight()-1), pos(0, 0)
{
	reset();
}

void Coin::update(float dt, float updateFrequency)
{
	static float dtElapsed = 0;
	tileMap.setTileTypeAtPos(TileMap::TileType::Coin, pos);

	dtElapsed += dt;
	if (dtElapsed > updateFrequency)
	{
		dtElapsed = 0;
		pos.x -= 1;
		if (pos.x == -1 || (player.getPos().x == pos.x && player.getPos().y == pos.y))
		{
			reset();
			if (pos.x != -1)
			{
				uf.setUpdateFrequency(uf.getUpdateFrequency() * updateFrequencyMultiply);
			}
		}
	}
}

void Coin::reset()
{
	do
	{
		pos.x = tileMap.getTileMapWith() - 1;
		pos.y = dist(rng);
	} while (tileMap.getTileTypeAtpos(pos) != TileMap::TileType::Blank);
	tileMap.setTileTypeAtPos(TileMap::TileType::Coin, pos);
}
