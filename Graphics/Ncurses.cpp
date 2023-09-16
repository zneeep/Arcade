/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include <iostream>

extern "C" std::string libName()
{
    return "ncurses";
}

extern "C" IRenderer *createLib()
{
    return new ncurses();
}

extern "C" void destroyLib(IRenderer *lib)
{
    delete lib;
    std::cout << "endwin done" << std::endl;
}

ncurses::ncurses()
{
    initscr();
    mainWindow = subwin(stdscr, 40, 40, 0, 0);
    box(mainWindow, ACS_VLINE, ACS_HLINE);
    wrefresh(mainWindow);
    noecho();
    cbreak();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);

}

ncurses::~ncurses()
{
    clear();
    endwin();
    std::cout << "exited of ncurses" << std::endl;
}

void ncurses::clearScreen()
{
    wclear(mainWindow);
    wclear(scoreWindow);
    box(mainWindow, ACS_VLINE, ACS_HLINE);
}

Input ncurses::getInput()
{
    int key = getch();

    switch (key) {
        case 'z':
            return Input::Z_KEY;
        case 's':
            return Input::S_KEY;
        case 'q':
            return Input::Q_KEY;
        case 'd':
            return Input::D_KEY;
        case KEY_RIGHT:
            return Input::ENTER;
        case KEY_DOWN:
            return Input::DOWN_ARROW;
        case KEY_UP:
            return Input::UP_ARROW;
        case 27:
            return Input::ESCAPE;
        default:
            return Input::NO_INPUT;
    }
}

void ncurses::displayAll(std::vector<std::string> Pixels)
{
    int x, y, height, width;
    getbegyx(mainWindow, y, x);
    getmaxyx(mainWindow, height, width);
    if (x != 45 || y != 0) {
        wclear(mainWindow);
        wrefresh(mainWindow);
        wresize(mainWindow, 40, 40);
        mvwin(mainWindow, 0, x + 45);
        wrefresh(mainWindow);
    }
    for (unsigned int i = 0; i < Pixels.size(); i++) {
        for (unsigned int j = 0; j < Pixels.at(i).size(); j++) {
            switch (Pixels.at(i)[j]) {
                case 0:
                    mvwprintw(mainWindow, i, j, " ");
                    break;
                case 1:
                    mvwprintw(mainWindow, i, j, "O");
                    break;
                case 2:
                    mvwprintw(mainWindow, i, j, "A");
                    break;
                case 3:
                    mvwprintw(mainWindow, i, j, "-");
                    break;
                case 4:
                    mvwprintw(mainWindow, i, j, "|");
                    break;
            }
        }
    }
    box(mainWindow, ACS_VLINE, ACS_HLINE);
}

void ncurses::refreshScreen()
{

    wrefresh(mainWindow);
    wrefresh(scoreWindow);
}

void ncurses::displayLib(std::vector<std::string> lib, short highLight)
{
    int line = 4;
    for (long unsigned int i = 0; i < lib.size() ; i++) {
        if (i == highLight) {
            wattron(mainWindow, A_REVERSE);
            mvwprintw(mainWindow, line++, 5,"%s",  lib[i].c_str());
            wattroff(mainWindow, A_REVERSE);
        }
        else
            mvwprintw(mainWindow, line++, 5, "%s", lib[i].c_str());
    }
}

void ncurses::displayGame(std::vector<std::string> game, short highLight)
{
    int line = 4;
    for (long unsigned int i = 0; i < game.size() ; i++) {
        if (i == highLight) {
            wattron(mainWindow, A_REVERSE);
            mvwprintw(mainWindow, line++, 5, "%s", game[i].c_str());
            wattroff(mainWindow, A_REVERSE);
        }
        else
            mvwprintw(mainWindow, line++, 5, "%s", game[i].c_str());
    }
}

void ncurses::displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) {}

void ncurses::printRectangle(std::pair<unsigned int, unsigned int> pos) {}

