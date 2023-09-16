/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** core
*/

#pragma once

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

typedef enum {
    NO_INPUT = -1,
    ENTER,
    BACKSPACE,
    SPACE,
    ESCAPE,
    UP_ARROW,
    DOWN_ARROW,
    LEFT_ARROW,
    RIGHT_ARROW,
    A_KEY,
    B_KEY,
    C_KEY,
    D_KEY,
    E_KEY,
    F_KEY,
    G_KEY,
    H_KEY,
    I_KEY,
    J_KEY,
    K_KEY,
    L_KEY,
    M_KEY,
    N_KEY,
    O_KEY,
    P_KEY,
    Q_KEY,
    R_KEY,
    S_KEY,
    T_KEY,
    U_KEY,
    V_KEY,
    W_KEY,
    X_KEY,
    Y_KEY,
    Z_KEY,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    QUIT_EVENT
} Input;

#include <filesystem>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <string>
#include <vector>
#include <iostream>
#include "libLoader.hpp"
#include "Games/IGames.hpp"
#include "Graphics/IRenderer.hpp"

class IRenderer;
class IGames;
class libLoader;

class core {
    public :
        core(std::string ArgLib);
        ~core() = default;
        void coreLoop();
        void menuLoop(Input input);
        void gameLoop(Input input);
        void menuInput(Input input);
        void gameInput(Input input);
        void chooseGame(Input input);
        void chooseLib(Input input);
        void changeGame();
        void changeLib();
        bool isGame;
        bool isMenu;
        bool menuType;
        libLoader loader;
        IRenderer *currentLib;
        IGames *currentGame;
        unsigned short gameIndex_;
        unsigned short graphicIndex_;
};
