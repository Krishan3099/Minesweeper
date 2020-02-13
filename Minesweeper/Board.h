#pragma once
#include "Tile.h"


using namespace std;


class Board
{
public:

	vector< vector<char> > mines;
	vector< vector<Tile> > boardTiles;
	bool debug;
	int flagCounter;
	int rightCounter;

	int FlagCount();
	bool CheckTilesWin();
	void Cascade(int n, int i);
	void DebugToggle();
	void HideAll();
	void ShowAll();
	void GenerateBoard();
	void GenerateTiles();
	void MinesToTiles();
	void GenerateFromFile(string filename);
	Board();
	int Random(int min, int max);
	~Board();
};

