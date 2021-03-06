#ifndef DEFINES_H
#define DEFINES_H

#include "Settings.h"

#define HashMap unordered_map
#define TileAmount 8						//Number of tiles in each chunk TileAmount*TileAmount
#define ChunkWidth (Settings::Tile::width*TileAmount)
#define ChunkHeight (Settings::Tile::height*TileAmount)

enum class STATE
{
	MAINMENU,
	SERVERLIST,
	GAME
};

#endif