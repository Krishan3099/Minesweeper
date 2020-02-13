#include "pch.h"
#include "Tile.h"


Tile::Tile() {
	tileSprite = "";
	hidden = true;
	flagged = false;
}

Tile::Tile(string tSprite)
{
	tileSprite = tSprite;
	hidden = true;
	flagged = false;

}

void Tile::SetTile(string spriteName) {
	tileSprite = spriteName;
}

void Tile::SetFlag(bool flag) {
	flagged = flag;
}
void Tile::SetHidden(bool hide) {
	hidden = hide;
}

string Tile::GetTile() {
	if (hidden == true && flagged == true) {
		return "flag.png";
	}
	else if (hidden == true && flagged == false) {
		return "tile_hidden.png";
	}else
		return tileSprite;

}

Tile::~Tile()
{
}
