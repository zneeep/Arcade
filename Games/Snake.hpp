/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Snake
*/

#pragma once

#include "IGames.hpp"

class snake : public IGames {
    public:
        snake();
        int getScore() override;
        bool IsOver() override;
        void handleInput(Input) override;
        void upDate() override;
        std::vector<std::string> getPixels() override;
        void resetGame() override;
        void setPause() override;
    protected:
    private:
        short direction;
        std::vector<Pixel> snakePixels;
        Pixel applePixel;
        float speed;
        void initSnake();
        void initApple();
        void eatApple();
        void goDirection();
        void moveSnake();
};
