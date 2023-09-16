/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Snake
*/

#include "Snake.hpp"

extern "C" IGames *createGame()
{
    return new snake();
}

extern "C" std::string gameName()
{
    std::string name = "snake";
    return name;
}

extern "C" void destroyGame(IGames *game)
{
    delete game;
}

std::vector<std::string> snake::getPixels()
{
    std::vector<std::string> pixels(40, std::string(40, 0));
    for (int i = 0; i < 40; i++) {
        pixels.at(i)[0] = 4;
        pixels.at(i)[39] = 4;
        pixels.at(0)[i] = 3;
        pixels.at(39)[i] = 3;
    }
    for (unsigned int i = 0; i < this->snakePixels.size(); i++)
        pixels.at(snakePixels.at(i).y).at(this->snakePixels.at(i).x) = 1;
    pixels.at(this->applePixel.y).at(this->applePixel.x) = 2;
    return pixels;
}

void snake::initSnake()
{
    Pixel snake;
    snake.x = 1;
    snake.y = 1;
    snake.color = 1;
    this->snakePixels.push_back(snake);
    this->direction = 0;
    this->speed = 3;
}

void snake::initApple()
{
    this->applePixel.x = 20;
    this->applePixel.y = 20;
    this->applePixel.color = 2;
}

snake::snake()
{
    this->direction = 0;
    this->isGameOver = false;
    initSnake();
    initApple();
}

void snake::goDirection()
{
    if (this->direction == 1)
        this->snakePixels.at(0).y -= 1;
    if (this->direction == 2)
        this->snakePixels.at(0).x += 1;
    if (this->direction == 3)
        this->snakePixels.at(0).y += 1;
    if(this->direction == 4)
        this->snakePixels.at(0).x -= 1;
}

bool snake::IsOver()
{
    for (unsigned int i = 1; i < this->snakePixels.size(); i++) {
        if ((this->snakePixels.at(i).x == this->snakePixels.at(0).x) &&
            (this->snakePixels.at(i).y == this->snakePixels.at(0).y))
            return true;
    }
    if (this->snakePixels.at(0).x == 0 || this->snakePixels.at(0).y == 0 || this->snakePixels.at(0).y == 39 ||
        this->snakePixels.at(0).x == 39)
        return true;
    return false;
}

void snake::moveSnake()
{
    int xNext = this->snakePixels.at(0).x;
    int yNext = this->snakePixels.at(0).y;
    int xPre;
    int yPre;
    goDirection();
    if (this->snakePixels.at(0).x == this->applePixel.x && 
    this->snakePixels.at(0).y == this->applePixel.y)
        eatApple();
    unsigned int i = 1;
    while (i < this->snakePixels.size()) {
        xPre = this->snakePixels.at(i).x;
        yPre = this->snakePixels.at(i).y;
        this->snakePixels.at(i).x = xNext;
        this->snakePixels.at(i).y = yNext;
        xNext = xPre;
        yNext = yPre;
        i++;
    }
}

void snake::handleInput(Input input)
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

void snake::upDate()
{

    if (this->direction == 0)
        return;
    static clock_t t = clock();
	clock_t now = clock();
	float delta = now - t;
	double speed = 0.10f;

	if (delta / CLOCKS_PER_SEC > speed) {
		t = clock();
		this->moveSnake();
	}
}

void snake::eatApple()
{
    std::srand(std::time(nullptr));
    int x = rand() % 38 + 1;
    int y = rand() % 38 + 1;

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
    this->applePixel.x = x;
    this->applePixel.y = y;
    this->snakePixels.push_back(newPixel);
    this->Score += 100;
}

int snake::getScore()
{
    return 0;
}

void snake::resetGame()
{
    initApple();
    this->snakePixels.clear();
    initSnake();
    this->direction = 0;
}

void snake::setPause()
{
    isPaused = !isPaused;
    if (isPaused)
        direction = 0;
}