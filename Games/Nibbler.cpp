/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** nibbler
*/

#include "Nibbler.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

extern "C" IGames *createGame()
{
    return new nibbler();
}

extern "C" std::string gameName()
{
    std::string name = "nibbler";
    return name;
}

extern "C" void destroyGame(IGames *game)
{
    delete game;
}

void nibbler::initNibbler()
{
    Pixel Nibbler;
    Nibbler.x = 1;
    Nibbler.y = 1;
    Nibbler.color = 1;
    this->snakePixels.push_back(Nibbler);
    this->direction = 0;
    this->speed = 3;
}

nibbler::nibbler() : direction(0)
{
    isGameOver = false;
    isPaused = false;
    Score = 0;
    this->initMap("Games/nibblermap1.txt");
    this->initNibbler();
}

void nibbler::initMap(const std::string& filePath)
 {
    std::vector<std::string> lines;
    std::ifstream fileStream(filePath);
    if (fileStream.is_open()) {
        std::string line;
        while (std::getline(fileStream, line)) {
            currentMap.push_back(line);
        }
        fileStream.close();
    }

    for (unsigned int i = 0; i < currentMap.size(); i++) {
        for (unsigned int j = 0; j < currentMap.at(i).size(); j++) {
            switch (currentMap.at(i)[j]) {
                case 32:
                    currentMap.at(i)[j] = 0;
                    break;
                case 65:
                    currentMap.at(i)[j] = 2;
                    break;
                case 95:
                    currentMap.at(i)[j] = 3;
                    break;
                case 124:
                    currentMap.at(i)[j] = 4;
                    break;
            }
        }
    }
}


std::vector<std::string> nibbler::getPixels()
{
    for (unsigned int i = 0; i < this->currentMap.size(); i++) {
        for (unsigned int j = 0; j < this->currentMap.at(i).size(); j++)
            if (currentMap[i][j] == 1)
                currentMap[i][j] = 0;
    }
    for (unsigned i = 0; i < this->snakePixels.size(); i++)
        this->currentMap[snakePixels.at(i).y][snakePixels.at(i).x] = 1;
    return this->currentMap;  
}

void nibbler::eatApple()
{
    Pixel newPixel;
    if (this->direction == 1) {
        newPixel.x = this->snakePixels.at(this->snakePixels.size() - 1).x;
        newPixel.y = this->snakePixels.at(this->snakePixels.size() - 1).y + 1;
    }
    if (this->direction == 2) {
        newPixel.x = this->snakePixels.at(this->snakePixels.size() - 1).x - 1;
        newPixel.y = this->snakePixels.at(this->snakePixels.size() - 1).y;
    }
    if (this->direction == 3) {
        newPixel.x = this->snakePixels.at(this->snakePixels.size() - 1).x;
        newPixel.y = this->snakePixels.at(this->snakePixels.size() - 1).y - 1;
    }
    if (this->direction == 4) {
        newPixel.x = this->snakePixels.at(this->snakePixels.size() - 1).x + 1;
        newPixel.y = this->snakePixels.at(this->snakePixels.size() - 1).y;
    }
    this->currentMap[snakePixels.at(0).y][snakePixels.at(0).x] = 0;
    this->snakePixels.push_back(newPixel);
    this->Score += 100;
}


bool nibbler::IsOver()
{
    for (unsigned int i = 1; i < this->snakePixels.size(); i++) {
        if ((this->snakePixels.at(i).x == this->snakePixels.at(0).x) &&
            (this->snakePixels.at(i).y == this->snakePixels.at(0).y))
            return true;
    }
    return false;
}

void nibbler::moveNibbler()
{
    int xNext = this->snakePixels.at(0).x;
    int yNext = this->snakePixels.at(0).y;
    int xPre;
    int yPre;
    goDirection();
    if (this->currentMap[snakePixels.at(0).y][snakePixels.at(0).x] == 2)
        eatApple();
    unsigned int i = 1;
    while (i < this->snakePixels.size() && direction != 0) {
        xPre = this->snakePixels.at(i).x;
        yPre = this->snakePixels.at(i).y;
        this->snakePixels.at(i).x = xNext;
        this->snakePixels.at(i).y = yNext;
        xNext = xPre;
        yNext = yPre;
        i++;
    }
}

void nibbler::handleInput(Input input)
{
    switch (input) {
        case E_KEY:
            this->isGameOver = true;
            break;
        case D_KEY:
            if (this->direction != 4)
                this->direction = 2;
            break;
        case S_KEY:
            if (this->direction != 1)
                this->direction = 3;
            break;
        case Q_KEY:
            if (this->direction != 2)
            this->direction = 4;
            break;
        case Z_KEY:
            if (this->direction != 3)
                this->direction = 1;
            break;
        default:
            break;
    }
}

void nibbler::upDate()
{
    static clock_t t = clock();
	clock_t now = clock();
	float delta = now - t;
	double speed = 0.10f;

	if (delta / CLOCKS_PER_SEC > speed) {
		t = clock();
		this->moveNibbler();
	}
}

void nibbler::goDirection()
{
    int x = snakePixels.at(0).x;
    int y = snakePixels.at(0).y;

    if (direction == 1 && (currentMap[y - 1][x] > 2))
        direction = 0;
    if (direction == 1 && (currentMap[y - 1][x] <= 2))
        snakePixels.at(0).y -= 1;
    if (direction == 2 && (currentMap[y][x + 1] > 2))
        direction = 0;
    if (direction == 2 && (currentMap[y][x + 1] <= 2))
        snakePixels.at(0).x += 1;
    if (direction == 3 && (currentMap[y + 1][x] > 2))
        direction = 0;
    if (direction == 3 && (currentMap[y + 1][x] <= 2))
        snakePixels.at(0).y += 1;
    if (direction == 4 && (currentMap[y][x - 1] > 2))
        direction = 0;
    if (direction == 4 && (currentMap[y][x - 1] <= 2))
        snakePixels.at(0).x -= 1;
}

int nibbler::getScore()
{
    return 0;
}

void nibbler::resetGame()
{
    this->snakePixels.clear();
    initNibbler();
    this->currentMap.clear();
    this->initMap("Games/nibblermap1.txt");
    this->direction = 0;
}

void nibbler::setPause()
{
    isPaused = !isPaused;
    if (isPaused)
        direction = 0;
}
