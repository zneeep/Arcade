/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** SDL
*/

#include <vector>
#include <string>
#include "IRenderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class SDL : public IRenderer {
    public:
        SDL();
        ~SDL();
        Input getInput() override;
        void displayAll(std::vector<std::string> Pixels) override;
        void refreshScreen() override;
        void clearScreen() override;
        void displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) override;
        void displayLib(std::vector<std::string> lib, short hightlight) override;
        void displayGame(std::vector<std::string> game, short hightlight) override;
        void printRectangle(std::pair<unsigned int, unsigned int> pos) override;

        SDL_Window *mainWindow;
        SDL_Window *scoreWindow;
        SDL_Window *window;
        SDL_Renderer *mainRenderer;
        SDL_Renderer *scoreRenderer;
        SDL_Renderer *renderer;
        TTF_Font* font;
        unsigned int characterSize;
};

extern "C" std::string libName();
extern "C" IRenderer *createLib();
extern "C" void destroyLib(IRenderer *lib);