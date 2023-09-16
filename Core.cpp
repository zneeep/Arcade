/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Core
*/

#include "Core.hpp"

std::vector<std::string> findLibsPaths(const std::filesystem::path& directory_path)
{
    std::vector<std::string> so_files;
    for (const auto& entry : std::filesystem::directory_iterator(directory_path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".so")
        {
            so_files.push_back(entry.path().string());
        }
    }
    return so_files;
}

core::core(std::string ArgLib) : loader(), isGame(false), gameIndex_(0), menuType(false), graphicIndex_(-1)
{
    graphicIndex_ = loader.getLibNames(findLibsPaths("./lib"), ArgLib);
    std::cout << graphicIndex_ << std::endl;
    loader.loadLib(loader.libs.at(graphicIndex_));
    currentLib = loader.libCtor();
}

void core::chooseGame(Input input)
{
    switch (input) {
        case UP_ARROW:
            if (gameIndex_ == 0)
                gameIndex_ = loader.games.size() - 1;
            else
                gameIndex_ -= 1;
            break;
        case DOWN_ARROW:
            if (gameIndex_ == loader.games.size() - 1)
                gameIndex_ = 0;
            else
                gameIndex_ += 1;
            break;
        case ENTER:
            changeGame();
            break;
        default:
            break;
    }

}

void core::chooseLib(Input input)
{
    switch (input) {
        case UP_ARROW:
            if (graphicIndex_ == 0)
                graphicIndex_ = loader.libs.size() - 1;
            else
                graphicIndex_ -= 1;
            break;
        case DOWN_ARROW:
            if (graphicIndex_ == loader.libs.size() - 1)
                graphicIndex_ = 0;
            else
                graphicIndex_ += 1;
            break;
        case ENTER:
            changeLib();
            break;
        default:
            break;
    }
}

void core::menuInput(Input input)
{
    if (input == Q_KEY) {
        if (currentGame != nullptr) {
            loader.gameDtor(currentGame);
            loader.closeGame();
        }
        loader.libDtor(currentLib);
        loader.closeLib();
        exit(0);
    } else if (input == ESCAPE) {
        menuType = !menuType;
        currentLib->clearScreen();
        currentLib->refreshScreen();
    } else {
        if (menuType == true)
            chooseLib(input);
        else
            chooseGame(input);
    }
}

void core::gameInput(Input input)
{
    if (input == ESCAPE) {
        currentGame->setPause();
        currentLib->clearScreen();
        currentLib->refreshScreen();
    } else if (currentGame->isPaused == true) {
        switch (input) {
            case Q_KEY:
                loader.gameDtor(currentGame);
                loader.closeGame();
                loader.libDtor(currentLib);
                loader.closeLib();
                exit(0);
            case UP_ARROW:
                if (graphicIndex_ == 0)
                    graphicIndex_ = loader.libs.size() - 1;
                else
                    graphicIndex_ -= 1;
                break;
            case DOWN_ARROW:
                if (graphicIndex_ == loader.libs.size() - 1)
                    graphicIndex_ = 0;
                else
                    graphicIndex_ += 1;
                break;
            case ENTER:
                changeLib();
                break;
        } 
    } else
        return;
}

void core::changeGame()
{
    if (currentGame != nullptr) {
        loader.gameDtor(currentGame);
        loader.closeGame();
        loader.loadGame(loader.games.at(gameIndex_));
        currentGame = loader.gameCtor();
    } else {
        loader.loadGame(loader.games.at(gameIndex_));
        currentGame = loader.gameCtor();
    }
    isGame = true;
}

void core::changeLib()
{
    currentLib->clearScreen();
    currentLib->refreshScreen();
    if (currentLib != nullptr) {
        loader.libDtor(currentLib);
        loader.closeLib();
        loader.loadLib(loader.libs.at(graphicIndex_));
        currentLib = loader.libCtor();
    } else {
        loader.loadLib(loader.libs.at(graphicIndex_));
        currentLib = loader.libCtor();
    }
}

void core::coreLoop()
{
    while (1) {
        if (isGame)
            gameLoop(currentLib->getInput());
        else 
            menuLoop(currentLib->getInput());
    }
}

void core::menuLoop(Input input)
{
    menuInput(input);
    if (menuType) {
        currentLib->displayLib(loader.libs, graphicIndex_);
        currentLib->refreshScreen();
    } else {
        currentLib->displayGame(loader.games, gameIndex_);
        currentLib->refreshScreen();
    }
}

void core::gameLoop(Input input)
{
    gameInput(input);
    if (currentGame->isPaused == true) {
        currentLib->displayLib(loader.libs, graphicIndex_);
        currentLib->refreshScreen();
    } else if (currentGame->IsOver() == false) {
        currentGame->handleInput(input);
        currentGame->upDate();
        currentLib->displayAll(currentGame->getPixels());
        currentLib->refreshScreen();
    } else {
        currentGame->resetGame();
        currentLib->displayAll(currentGame->getPixels());
        currentLib->refreshScreen();
    }
}
