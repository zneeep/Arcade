/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** libLoader
*/

#include "libLoader.hpp"

void libLoader::loadLib(std::string libName)
{
    std::string libToOpen = "./lib/arcade_" + libName + ".so";
    std::cout << libToOpen << std::endl;
    auto newLib = dlopen(libToOpen.c_str(), RTLD_NOW);
    if (newLib == nullptr) {
        std::cerr << "Failed to load library: " << dlerror() << std::endl;
        exit(84);
    }
    graphicLib = newLib;
    void *createLib = dlsym(graphicLib, "createLib");
    void *destroyLib = dlsym(graphicLib, "destroyLib"); 
    
    this->libCtor = (IRenderer *(*)())(createLib);
    this->libDtor = (void (*)(IRenderer *))(destroyLib);
}

void libLoader::closeLib()
{

    dlclose(this->graphicLib);
}

void libLoader::loadGame(std::string gameName)
{
    std::string libToOpen = "lib/arcade_" + gameName + ".so";
    gameLib = dlopen(libToOpen.c_str(), RTLD_NOW);
    if (gameLib == nullptr) {
        std::cerr << "Failed to load library: " << dlerror() << std::endl;
        exit(84);
    }
    void *createGame = dlsym(gameLib, "createGame");
    void *destroyGame = dlsym(gameLib, "destroyGame"); 
    
    this->gameCtor = (IGames *(*)())(createGame);
    this->gameDtor = (void (*)(IGames *))(destroyGame);    
}

void libLoader::closeGame()
{
    dlclose(this->gameLib);
}

int libLoader::getLibNames(std::vector<std::string> libsNames, std::string ArgLib)
{
    int index = -1;
    std::string Name;
    for (unsigned int i = 0; i < libsNames.size(); i++) {
        if (libsNames.at(i) == ArgLib)
            index = i - games.size();
        auto entry = dlopen(libsNames.at(i).c_str(), RTLD_NOW);
        auto gameName = dlsym(entry, "gameName");
        auto libName = dlsym(entry, "libName");
        if (gameName != nullptr) {
            std::string Name = reinterpret_cast<std::string(*)()>(gameName)();
            games.push_back(Name);
        } else  if (libName != nullptr) {
            std::string Name = reinterpret_cast<std::string(*)()>(libName)();
            libs.push_back(Name);
        } else {
            std::cout << "Not valid library" << dlerror() << std::endl;
            dlclose(entry);
            exit(84);
        }
        dlclose(entry);
    }
    if (index == -1) {
        std::cout << "Library not found" << std::endl;
        exit(84);
    }

    for (ssize_t i = 0; i < this->libs.size(); i++)
        std::cout << "lib n° " << i << libs.at(i) << std::endl;
    return index;
}
