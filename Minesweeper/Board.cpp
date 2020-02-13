#include "pch.h"
#include "Board.h"


Board::Board()
{
	mines.resize(25);
	boardTiles.resize(25);
	for (int n = 0; n < 25; n++) {
		mines[n].resize(16, 0);
		boardTiles[n].resize(16);
	}
	debug = false;
	rightCounter = 0;
	flagCounter = 0;
	GenerateBoard();
}


void Board::GenerateBoard(){
	int count = 50;
	unsigned int x = 0;
	unsigned int y = 0;
 
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			mines[n][i] = 0;
		}
	}

	while (count > 0) {
		x = (unsigned int)Random(0, 24);
		y = (unsigned int)Random(0, 15);
		if (mines[x][y] != 1) {
			mines[x][y] = 1;
			count--;
		}
	}
}

void Board::GenerateTiles() {
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			if (mines[n][i] == 1) {
				if (n == 0 && i == 0) {
					if (mines[n + 1][i] != 1) {
						mines[n + 1][i]--;
					}if (mines[n][i+1] != 1) {
						mines[n][i+1]--;
					}if (mines[n + 1][i+1] != 1) {
						mines[n + 1][i+1]--;
					}
				}
				else if (n == 24 && i == 0) {
					if (mines[n - 1][i] != 1) {
						mines[n - 1][i]--;
					}if (mines[n][i + 1] != 1) {
						mines[n][i + 1]--;
					}if (mines[n - 1][i + 1] != 1) {
						mines[n - 1][i + 1]--;
					}
				}
				else if (n == 24 && i == 15) {
					if (mines[n - 1][i] != 1) {
						mines[n - 1][i]--;
					}if (mines[n][i - 1] != 1) {
						mines[n][i - 1]--;
					}if (mines[n - 1][i - 1] != 1) {
						mines[n - 1][i - 1]--;
					}
				}
				else if (n == 0 && i == 15) {
					if (mines[n + 1][i] != 1) {
						mines[n + 1][i]--;
					}if (mines[n][i - 1] != 1) {
						mines[n][i - 1]--;
					}if (mines[n + 1][i - 1] != 1) {
						mines[n + 1][i - 1]--;
					}
				}
				else if (n == 0) {
					if (mines[n][i - 1] != 1) {
						mines[n][i - 1]--;
					}
					if (mines[n][i + 1] != 1) {
						mines[n][i + 1]--;
					}
					if (mines[n+1][i - 1] != 1) {
						mines[n+1][i - 1]--;
					}
					if (mines[n+1][i] != 1) {
						mines[n+1][i]--;
					}
					if (mines[n+1][i + 1] != 1) {
						mines[n+1][i + 1]--;
					}
				}
				else if (n == 24) {
					if (mines[n][i - 1] != 1) {
						mines[n][i - 1]--;
					}
					if (mines[n][i + 1] != 1) {
						mines[n][i + 1]--;
					}
					if (mines[n - 1][i - 1] != 1) {
						mines[n - 1][i - 1]--;
					}
					if (mines[n - 1][i] != 1) {
						mines[n - 1][i]--;
					}
					if (mines[n - 1][i + 1] != 1) {
						mines[n - 1][i + 1]--;
					}
				}
				else if (i == 0) {
					if (mines[n-1][i] != 1) {
						mines[n-1][i]--;
					}
					if (mines[n+1][i] != 1) {
						mines[n+1][i]--;
					}
					if (mines[n - 1][i + 1] != 1) {
						mines[n - 1][i + 1]--;
					}
					if (mines[n][i + 1] != 1) {
						mines[n][i + 1]--;
					}
					if (mines[n + 1][i + 1] != 1) {
						mines[n + 1][i + 1]--;
					}
				}
				else if (i == 15) {
					if (mines[n - 1][i] != 1) {
						mines[n - 1][i]--;
					}
					if (mines[n + 1][i] != 1) {
						mines[n + 1][i]--;
					}
					if (mines[n - 1][i - 1] != 1) {
						mines[n - 1][i - 1]--;
					}
					if (mines[n][i - 1] != 1) {
						mines[n][i - 1]--;
					}
					if (mines[n + 1][i - 1] != 1) {
						mines[n + 1][i - 1]--;
					}
				}
				else {
					if (mines[n - 1][i] != 1) {
						mines[n - 1][i]--;
					}
					if (mines[n + 1][i] != 1) {
						mines[n + 1][i]--;
					}
					if (mines[n - 1][i - 1] != 1) {
						mines[n - 1][i - 1]--;
					}
					if (mines[n + 1][i + 1] != 1) {
						mines[n + 1][i + 1]--;
					}
					if (mines[n - 1][i + 1] != 1) {
						mines[n - 1][i + 1]--;
					}
					if (mines[n + 1][i - 1] != 1) {
						mines[n + 1][i - 1]--;
					}
					if (mines[n][i - 1] != 1) {
						mines[n][i - 1]--;
					}
					if (mines[n][i + 1] != 1) {
						mines[n][i + 1]--;
					}
				}
			}
		}
	}

	MinesToTiles();
}

void Board::MinesToTiles() {
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			Tile aTile;
			switch (mines[n][i])
			{
			case -8:
				aTile.SetTile("number_8.png");
				boardTiles[n][i] = aTile;
				break;
			case -7:
				aTile.SetTile("number_7.png");
				boardTiles[n][i] = aTile;
				break;
			case -6:
				aTile.SetTile("number_6.png");
				boardTiles[n][i] = aTile;
				break;
			case -5:
				aTile.SetTile("number_5.png");
				boardTiles[n][i] = aTile;
				break;
			case -4:
				aTile.SetTile("number_4.png");
				boardTiles[n][i] = aTile;
				break;
			case -3:
				aTile.SetTile("number_3.png");
				boardTiles[n][i] = aTile;
				break;
			case -2:
				aTile.SetTile("number_2.png");
				boardTiles[n][i] = aTile;
				break;
			case -1:
				aTile.SetTile("number_1.png");
				boardTiles[n][i] = aTile;
				break;
			case 0:
				aTile.SetTile("tile_revealed.png");
				boardTiles[n][i] = aTile;
				break;
			case 1:
				aTile.SetTile("mine.png");
				boardTiles[n][i] = aTile;
				break;
			}
		}
	}
}

bool Board::CheckTilesWin() {
	rightCounter = 0;
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			if (boardTiles[n][i].flagged == true && mines[n][i] == 1)
				rightCounter++;
		}
	}
	if (rightCounter == 50) {
		return true;
	}
	else
		return false;
}

void Board::GenerateFromFile(string filename) {
	string newline = "";
	fstream myFile(filename, fstream::in);
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			myFile >> noskipws >> mines[n][i];
			static_cast<char>(mines[n][i]);
		}
		getline(myFile, newline, '\n');
	}
	MinesToTiles();
}

int Board::Random(int min, int max)
{
	mt19937 random_mt;
	random_mt.seed(time(NULL));
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void Board::Cascade(int n, int i) {
	boardTiles[n][i].SetHidden(false);
	if (n == 0 && i == 0) {
		if (mines[n + 1][i] == 0 && boardTiles[n + 1][i].hidden == true) {
			Cascade(n + 1, i);
		}else
			boardTiles[n+1][i].SetHidden(false);

		if (mines[n][i + 1] == 0 && boardTiles[n][i+1].hidden == true) {
			Cascade(n, i + 1);
		}
		else
			boardTiles[n][i+1].SetHidden(false);

		if (mines[n + 1][i + 1] == 0 && boardTiles[n + 1][i+1].hidden == true) {
			Cascade(n + 1, i + 1);
		}
		else
			boardTiles[n + 1][i+1].SetHidden(false);
	}
	else if (n == 24 && i == 0) {
		if (mines[n - 1][i] == 0 && boardTiles[n - 1][i].hidden == true) {
			Cascade(n - 1, i);
		}
		else
			boardTiles[n - 1][i].SetHidden(false);
		if (mines[n][i + 1] == 0 && boardTiles[n][i+1].hidden == true) {
			Cascade(n, i + 1);
		}
		else
			boardTiles[n][i + 1].SetHidden(false);
		if (mines[n - 1][i + 1] == 0 && boardTiles[n - 1][i+1].hidden == true) {
			Cascade(n - 1, i + 1);
		}
		else
			boardTiles[n - 1][i + 1].SetHidden(false);
	}
	else if (n == 24 && i == 15) {
		if (mines[n - 1][i] == 0 && boardTiles[n - 1][i].hidden == true) {
			Cascade(n - 1, i);
		}
		else
			boardTiles[n - 1][i].SetHidden(false);

		if (mines[n][i - 1] == 0 && boardTiles[n][i-1].hidden == true) {
			Cascade(n, i - 1);
		}
		else
			boardTiles[n][i - 1].SetHidden(false);

		if (mines[n - 1][i - 1] == 0 && boardTiles[n - 1][i-1].hidden == true) {
			Cascade(n - 1, i - 1);
		}
		else
			boardTiles[n - 1][i - 1].SetHidden(false);
	}
	else if (n == 0 && i == 15) {
		if (mines[n + 1][i] == 0 && boardTiles[n + 1][i].hidden == true) {
			Cascade(n + 1, i);
		}
		else
			boardTiles[n + 1][i].SetHidden(false);
		if (mines[n][i - 1] == 0 && boardTiles[n][i-1].hidden == true) {
			Cascade(n, i - 1);
		}
		else
			boardTiles[n][i - 1].SetHidden(false);
		if (mines[n + 1][i - 1] == 0 && boardTiles[n + 1][i-1].hidden == true) {
			Cascade(n + 1, i - 1);
		}
		else
			boardTiles[n + 1][i - 1].SetHidden(false);
	}
	else if (n == 0) {
		if (mines[n][i - 1] == 0 && boardTiles[n][i-1].hidden == true) {
			Cascade(n, i - 1);
		}else
			boardTiles[n][i - 1].SetHidden(false);

		if (mines[n][i + 1] == 0 && boardTiles[n][i+1].hidden == true) {
			Cascade(n, i + 1);
		}
		else
			boardTiles[n][i + 1].SetHidden(false);

		if (mines[n + 1][i - 1] == 0 && boardTiles[n + 1][i-1].hidden == true) {
			Cascade(n+1, i - 1);
		}
		else
			boardTiles[n+1][i - 1].SetHidden(false);

		if (mines[n + 1][i] == 0 && boardTiles[n + 1][i].hidden == true) {
			Cascade(n+1, i);
		}
		else
			boardTiles[n+1][i].SetHidden(false);

		if (mines[n + 1][i + 1] == 0 && boardTiles[n + 1][i+1].hidden == true) {
			Cascade(n+1, i + 1);
		}
		else
			boardTiles[n+1][i + 1].SetHidden(false);
	}
	else if (n == 24) {
		if (mines[n][i - 1] == 0 && boardTiles[n][i-1].hidden == true) {
			Cascade(n, i - 1);
		}
		else
			boardTiles[n][i - 1].SetHidden(false);

		if (mines[n][i + 1] == 0 && boardTiles[n][i+1].hidden == true) {
			Cascade(n, i + 1);
		}
		else
			boardTiles[n][i + 1].SetHidden(false);

		if (mines[n - 1][i - 1] == 0 && boardTiles[n - 1][i-1].hidden == true) {
			Cascade(n - 1, i - 1);
		}
		else
			boardTiles[n - 1][i - 1].SetHidden(false);

		if (mines[n - 1][i] == 0 && boardTiles[n - 1][i].hidden == true) {
			Cascade(n - 1, i);
		}
		else
			boardTiles[n - 1][i].SetHidden(false);

		if (mines[n - 1][i + 1] == 0 && boardTiles[n - 1][i+1].hidden == true) {
			Cascade(n - 1, i + 1);
		}
		else
			boardTiles[n - 1][i + 1].SetHidden(false);
	}
	else if (i == 0) {
		if (mines[n-1][i] == 0 && boardTiles[n - 1][i].hidden == true) {
			Cascade(n-1, i);
		}
		else
			boardTiles[n-1][i].SetHidden(false);

		if (mines[n+1][i] == 0 && boardTiles[n + 1][i].hidden == true) {
			Cascade(n+1, i);
		}
		else
			boardTiles[n+1][i].SetHidden(false);

		if (mines[n - 1][i + 1] == 0 && boardTiles[n - 1][i+1].hidden == true) {
			Cascade(n - 1, i + 1);
		}
		else
			boardTiles[n - 1][i + 1].SetHidden(false);

		if (mines[n + 1][i+1] == 0 && boardTiles[n+1][i+1].hidden == true) {
			Cascade(n + 1, i+1);
		}
		else
			boardTiles[n + 1][i+1].SetHidden(false);

		if (mines[n][i + 1] == 0 && boardTiles[n][i+1].hidden == true) {
			Cascade(n, i + 1);
		}
		else
			boardTiles[n][i + 1].SetHidden(false);
	}
	else if (i == 15) {
		if (mines[n - 1][i] == 0 && boardTiles[n - 1][i].hidden == true) {
			Cascade(n - 1, i);
		}
		else
			boardTiles[n - 1][i].SetHidden(false);

		if (mines[n + 1][i] == 0 && boardTiles[n + 1][i].hidden == true) {
			Cascade(n + 1, i);
		}
		else
			boardTiles[n + 1][i].SetHidden(false);

		if (mines[n - 1][i - 1] == 0 && boardTiles[n - 1][i-1].hidden == true) {
			Cascade(n - 1, i - 1);
		}
		else
			boardTiles[n - 1][i - 1].SetHidden(false);

		if (mines[n][i - 1] == 0 && boardTiles[n][i-1].hidden == true) {
			Cascade(n, i - 1);
		}
		else
			boardTiles[n][i - 1].SetHidden(false);

		if (mines[n + 1][i - 1] == 0 && boardTiles[n + 1][i-1].hidden == true) {
			Cascade(n + 1, i - 1);
		}
		else
			boardTiles[n + 1][i - 1].SetHidden(false);
	}
	else {
		if (mines[n + 1][i] == 0 && boardTiles[n + 1][i].hidden == true) {
			Cascade(n + 1, i);
		}
		else
			boardTiles[n + 1][i].SetHidden(false);

		if (mines[n - 1][i] == 0 && boardTiles[n - 1][i].hidden == true) {
			Cascade(n - 1, i);
		}
		else
			boardTiles[n - 1][i].SetHidden(false);

		if (mines[n][i + 1] == 0 && boardTiles[n][i+1].hidden == true) {
			Cascade(n, i + 1);
		}
		else
			boardTiles[n][i + 1].SetHidden(false);

		if (mines[n][i - 1] == 0 && boardTiles[n][i-1].hidden == true) {
			Cascade(n, i - 1);
		}
		else
			boardTiles[n][i - 1].SetHidden(false);

		if (mines[n + 1][i + 1] == 0 && boardTiles[n + 1][i+1].hidden == true) {
			Cascade(n + 1, i + 1);
		}
		else
			boardTiles[n + 1][i + 1].SetHidden(false);
		
		if (mines[n - 1][i-1] == 0 && boardTiles[n - 1][i-1].hidden == true) {
			Cascade(n - 1, i-1);
		}
		else
			boardTiles[n - 1][i-1].SetHidden(false);

		if (mines[n + 1][i-1] == 0 && boardTiles[n + 1][i-1].hidden == true) {
			Cascade(n + 1, i-1);
		}
		else
			boardTiles[n + 1][i-1].SetHidden(false);

		if (mines[n - 1][i + 1] == 0 && boardTiles[n - 1][i+1].hidden == true) {
			Cascade(n - 1, i + 1);
		}
		else
			boardTiles[n - 1][i + 1].SetHidden(false);

	}
}

int Board::FlagCount() {
	flagCounter = 0;
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			if (boardTiles[n][i].hidden == true && boardTiles[n][i].flagged == true) {
				flagCounter++;
			}
		}
	}
	return 50 - flagCounter;
}

void Board::ShowAll() {
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			boardTiles[n][i].SetHidden(false);
		}
	}
}

void Board::HideAll() {
	for (int n = 0; n < 25; n++) {
		for (int i = 0; i < 16; i++) {
			boardTiles[n][i].SetHidden(true);
		}
	}
}

void Board::DebugToggle() {
	if (debug == false) {
		ShowAll();
		debug = true;
	}
	else if (debug == true) {
		HideAll();
		debug = false;
	}
}

Board::~Board()
{

}
