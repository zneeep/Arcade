/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** libLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include <filesystem>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <string>
#include <vector>
#include <iostream>

class IRenderer;
class IGames;

class libLoader 
{
    public :
        libLoader() = default;
        ~libLoader() = default;
        void loadLib(std::string libName);
        void closeLib();
        void loadGame(std::string gameName);
        void closeGame();
        int getLibNames(std::vector<std::string> libsNames, std::string ArgLib);

        void *graphicLib;
        void *gameLib;
        std::vector<std::string> games;
        std::vector<std::string> libs;
        using GameCreator = IGames *(*)();
        using GameDestroyer = void (*)(IGames *);
        using LibCreator = IRenderer *(*)();
        using LibDestroyer = void (*)(IRenderer *);
        GameCreator gameCtor;
        GameDestroyer gameDtor;
        LibCreator libCtor;
        LibDestroyer libDtor;
};

#endif /* !LIBLOADER_HPP_ */
