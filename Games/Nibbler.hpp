/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** nibbler
*/

#pragma once

#include "IGames.hpp"

class nibbler : public IGames {
    public:
        nibbler();
        int getScore() override;
        bool IsOver() override;
        void handleInput(Input) override;
        void upDate() override;
        std::vector<std::string> getPixels() override;
        void resetGame() override;
        void setPause() override;
    protected:
    private:
        std::vector<Pixel> snakePixels;
        float speed;
        short direction;
        void initMap(const std::string& filePath);
        void initNibbler();
        void eatApple();
        void goDirection();
        void moveNibbler();
        std::vector<std::string> currentMap;
};
