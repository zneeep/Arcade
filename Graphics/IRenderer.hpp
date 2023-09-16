/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** IRenderer
*/

#pragma once

#include "../Core.hpp"

class IRenderer {
    public:
        virtual ~IRenderer() = default;
        virtual Input getInput() = 0;
        virtual void displayAll(std::vector<std::string> Pixels) = 0;
        virtual void refreshScreen() = 0;
        virtual void clearScreen() = 0;
        virtual void displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) = 0;
        virtual void displayLib(std::vector<std::string> lib, short highLight) = 0;
        virtual void displayGame(std::vector<std::string> game, short highLight) = 0;
        virtual void printRectangle(std::pair<unsigned int, unsigned int> pos) = 0;
};
