#include "Tile.h"

using namespace std;

void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}

Tile::Tile(Coordinate* positionIn, Shape* northAreaIn, Shape* southAreaIn, Shape* westAreaIn, Shape* eastAreaIn)
{
	position = positionIn;
	northArea = northAreaIn;
	southArea = southAreaIn;
	westArea = westAreaIn;
	eastArea = eastAreaIn;
}

Tile::Tile(SDL_Renderer* ren, string s)
{
	tex = IMG_LoadTexture(ren, s.c_str());
}

Tile::~Tile(void)
{
	delete position;
	delete northArea;
	delete southArea;
	delete westArea;
	delete eastArea;
}

SDL_Texture* Tile::getTexture() {
    return tex;
}