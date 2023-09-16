/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Ncurses
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_LUCAS_SIRAUX_NCURSES_H
#define B_OOP_400_LYN_4_1_ARCADE_LUCAS_SIRAUX_NCURSES_H

#include "IRenderer.hpp"
#include <ncurses.h>

class ncurses : public IRenderer {

    public :
        ncurses();
        ~ncurses();
        Input getInput() override;
        void displayAll(std::vector<std::string> Pixels) override;
        void refreshScreen() override;
        void clearScreen() override;
        void displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) override;
        void displayLib(std::vector<std::string> lib, short highLight) override;
        void displayGame(std::vector<std::string> game, short highLight) override;
        void printRectangle(std::pair<unsigned int, unsigned int> pos) override;
        WINDOW *scoreWindow;
        WINDOW *mainWindow;
};

extern "C" std::string libName();
extern "C" IRenderer *createLib();
extern "C" void destroyLib(IRenderer *lib);

#endif //B_OOP_400_LYN_4_1_ARCADE_LUCAS_SIRAUX_NCURSES_H
