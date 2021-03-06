// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <iostream>

using namespace std;

void TextureToSpriteMap(map<string, sf::Sprite> &toEdit, string filename);
sf::Texture *texture;


int main()
{                                                                                                                                                                                                                
	map<string, sf::Sprite> SpriteMap;

	TextureToSpriteMap(SpriteMap, "mine.png");
	TextureToSpriteMap(SpriteMap, "tile_hidden.png");
	TextureToSpriteMap(SpriteMap, "tile_revealed.png");
	TextureToSpriteMap(SpriteMap, "flag.png");
	TextureToSpriteMap(SpriteMap, "face_happy.png");
	TextureToSpriteMap(SpriteMap, "face_win.png");
	TextureToSpriteMap(SpriteMap, "face_lose.png");
	TextureToSpriteMap(SpriteMap, "debug.png");
	TextureToSpriteMap(SpriteMap, "test_1.png");
	TextureToSpriteMap(SpriteMap, "test_2.png");
	texture = new sf::Texture;
	TextureToSpriteMap(SpriteMap, "digits.png");

	string num = "";
	for (int i = 1; i <= 8; i++) {
		num = "number_" + to_string(i) + ".png";
		TextureToSpriteMap(SpriteMap, num);
	}

	Board newBoard;
	newBoard.GenerateTiles();
	//newBoard.GenerateFromFile("boards\\testboard.brd");

	sf::RenderWindow window(sf::VideoMode(800, 600), "Mysweeper");

	string dig1 = "";
	string dig2 = "";
	int iPos = 0;
	int jPos = 0;
	int loseFlag = 0;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				iPos = floor(event.mouseButton.x / 32);
				jPos = floor(event.mouseButton.y / 32);
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				cout << endl << "boardTiles[" << iPos << "][" << jPos << "]" << endl << endl;

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
				
					if (event.mouseButton.x >= (10 * 64) && event.mouseButton.x <= (10 * 64) + 64 && event.mouseButton.y >= (8 * 64) && event.mouseButton.y <= (8 * 64) + 64) {
						newBoard.GenerateFromFile("boards\\testboard2.brd");
						newBoard.GenerateTiles();
					}
					else if (event.mouseButton.x >= (9 * 64) && event.mouseButton.x <= (9 * 64) + 64 && event.mouseButton.y >= (8 * 64) && event.mouseButton.y <= (8 * 64) + 64) {
						newBoard.GenerateFromFile("boards\\testboard.brd");
						newBoard.GenerateTiles();
					}
					else if (event.mouseButton.x >= (6 * 64) && event.mouseButton.x <= (6 * 64) + 64 && event.mouseButton.y >= (8 * 64) && event.mouseButton.y <= (8 * 64) + 64) {
						newBoard.GenerateBoard();
						newBoard.GenerateTiles();
					}else if (event.mouseButton.x >= (8 * 64) && event.mouseButton.x <= (8 * 64) + 64 && event.mouseButton.y >= (8 * 64) && event.mouseButton.y <= (8 * 64) + 64) {
						newBoard.DebugToggle();
					}
					else if (event.mouseButton.x >= 0 && event.mouseButton.x <= 800 && event.mouseButton.y >= 0 && event.mouseButton.y <= 512) {
						if (newBoard.mines[iPos][jPos] == 0 && newBoard.boardTiles[iPos][jPos].hidden == true) {
							newBoard.Cascade(iPos, jPos);
						}
						else if (newBoard.boardTiles[iPos][jPos].tileSprite == "mine.png" && newBoard.boardTiles[iPos][jPos].hidden == true) {
							loseFlag = -1;
							newBoard.ShowAll();
						}
						else if (newBoard.boardTiles[iPos][jPos].hidden == true) {
							newBoard.boardTiles[iPos][jPos].SetHidden(false);
						}
					}
					
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					std::cout << "the right button was pressed" << std::endl;
					if (event.mouseButton.x >= 0 && event.mouseButton.x <= 800 && event.mouseButton.y >= 0 && event.mouseButton.y <= 512) {
						if (newBoard.boardTiles[iPos][jPos].flagged == false && newBoard.FlagCount() > 0) {
							newBoard.boardTiles[iPos][jPos].SetFlag(true);
						}
						else if (newBoard.boardTiles[iPos][jPos].flagged == true && newBoard.FlagCount() < 50) {
							newBoard.boardTiles[iPos][jPos].SetFlag(false);
						}
					}
				}
				
			}
		}
		if (newBoard.CheckTilesWin() == true) {
			loseFlag = 1;
		}

		window.clear(sf::Color::Black);

		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 16; j++) {

				SpriteMap["tile_revealed.png"].setPosition(sf::Vector2f((i * 32), (j * 32)));
				SpriteMap[newBoard.boardTiles[i][j].GetTile()].setPosition(sf::Vector2f((i * 32), (j * 32)));
				window.draw(SpriteMap["tile_revealed.png"]);
				window.draw(SpriteMap[newBoard.boardTiles[i][j].GetTile()]);
			}
		}

		/*
			
		*/
		if (to_string(newBoard.FlagCount()).size() == 1) {
			dig2 = to_string(newBoard.FlagCount()).at(0);
			dig1 = "0";
		}else if(to_string(newBoard.FlagCount()).size() > 1){
			dig1 = to_string(newBoard.FlagCount()).at(0);
			dig2 = to_string(newBoard.FlagCount()).at(1);
		}


		window.draw(SpriteMap["debug.png"]);
		SpriteMap["debug.png"].setPosition(sf::Vector2f((8 * 64), (8 * 64)));

		window.draw(SpriteMap["test_1.png"]);
		SpriteMap["test_1.png"].setPosition(sf::Vector2f((9 * 64), (8 * 64)));

		window.draw(SpriteMap["test_2.png"]);
		SpriteMap["test_2.png"].setPosition(sf::Vector2f((10 * 64), (8 * 64)));

		window.draw(SpriteMap["digits_0.png"]);
		SpriteMap["digits_0.png"].setPosition(sf::Vector2f((0 * 32), (15 * 34)));

		window.draw(SpriteMap["digits_" + dig1 + ".png"]);
		SpriteMap["digits_" + dig1 + ".png"].setPosition(sf::Vector2f((0.6 * 32), (15 * 34)));

		window.draw(SpriteMap["digits_" + dig2 + ".png"]);
		SpriteMap["digits_" + dig2 + ".png"].setPosition(sf::Vector2f((1.2 * 32), (15 * 34)));

		
		if (loseFlag == -1) {
			window.draw(SpriteMap["face_lose.png"]);
			SpriteMap["face_lose.png"].setPosition(sf::Vector2f((6 * 64), (8 * 64)));
		}
		else if(loseFlag == 1) {
			window.draw(SpriteMap["face_win.png"]);
			SpriteMap["face_win.png"].setPosition(sf::Vector2f((6 * 64), (8 * 64)));

		}
		else {
			window.draw(SpriteMap["face_happy.png"]);
			SpriteMap["face_happy.png"].setPosition(sf::Vector2f((6 * 64), (8 * 64)));
		}
		
		
		window.display();

	}
	return 0;
}

void TextureToSpriteMap(map<string, sf::Sprite> &toEdit, string filename) {
	sf::Sprite sprite;

	string dir = "images\\" + filename;
												 
																							
	if (filename != "digits.png")															//if the digits.png is not encountered, 
	{																						//then load from an already sized file
		
		texture = new sf::Texture;															//in order for texture to not fall out of refrerence...
		if (!texture->loadFromFile(dir))												//...it must be dynamically allocated each time the function is run
		{
			exit(0);			
		}
		sprite.setTexture(*texture);
		toEdit.emplace(filename, sprite);
		
	
	}
	else {																					//if digits.png is encountered...
	
		unsigned int pixelCount = 0;
		string digName = "";
		for (int i = 0; i <= 9; i++) {														//...a for loop is run for each digit and...
			if (!texture->loadFromFile("images\\digits.png", sf::IntRect(pixelCount, 0, 21, 32)))	//...the texture loaded is shaped each time to a new digit rectangle
			{
				exit(0);
			}
			sprite.setTexture(*texture);
			digName = "digits_" + to_string(i) + ".png";									//the name each sprite recieves will be in the form of digits_#.png
			toEdit.emplace(digName, sprite);
			texture = new sf::Texture;														//a new dynamically stored texture must be created for each iteration
			pixelCount += 21;												
			
		}
		
	}	
}

