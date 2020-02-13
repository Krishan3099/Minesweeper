#pragma once
#include <map>
#include <string>
#include <random>
#include <vector>
#include <time.h>
#include <cmath>
#include <fstream>

using namespace std;

class Tile
{
public:
	bool hidden;
	bool flagged;

	string tileSprite;

	void SetFlag(bool flag);
	void SetHidden(bool hide);

	void SetTile(string spriteName);
	string GetTile();

	Tile();
	Tile(string tSprite);
	~Tile();
};

