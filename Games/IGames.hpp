/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** IGames
*/

#pragma once

#include "../Core.hpp"

class IGames {
    public:
        virtual ~IGames() = default;
        virtual int getScore() = 0;
        virtual bool IsOver() = 0;
        virtual void handleInput(Input) = 0;
        virtual void upDate() = 0;
        virtual std::vector<std::string> getPixels() = 0;
        virtual void resetGame() = 0;
        virtual void setPause() = 0;
        bool isGameOver;
        bool isPaused;
        int Score;
    protected:
    private:
};
