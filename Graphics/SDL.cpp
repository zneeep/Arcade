/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** SDL
*/

#include "SDL.hpp"

extern "C" std::string libName()
{
    return "sdl2";
}

extern "C" IRenderer *createLib()
{
    return new SDL();
}

extern "C" void destroyLib(IRenderer *lib)
{
    delete lib;
}

SDL::SDL() : characterSize(20) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    mainWindow = SDL_CreateWindow("SDL2 main window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    scoreWindow = SDL_CreateWindow("SDL2 score window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
    scoreRenderer = SDL_CreateRenderer(scoreWindow, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("arial.ttf", characterSize);
}

SDL::~SDL()
{
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyRenderer(scoreRenderer);
    SDL_DestroyWindow(mainWindow);
    SDL_DestroyWindow(scoreWindow);
    SDL_Quit();
}

void SDL::refreshScreen()
{
    SDL_RenderPresent(mainRenderer);
}

void SDL::clearScreen() {
    SDL_RenderClear(mainRenderer);
}

Input SDL::getInput() {
    SDL_Event event;

     while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_z:
                        return Input::Z_KEY;
                    case SDLK_s:
                        return Input::S_KEY;
                    case SDLK_q:
                        return Input::Q_KEY;
                    case SDLK_d:
                        return Input::D_KEY;
                    case SDLK_RIGHT:
                        return Input::ENTER;
                    case SDLK_DOWN:
                        return Input::DOWN_ARROW;
                    case SDLK_UP:
                        return Input::UP_ARROW;
                    case SDLK_ESCAPE:
                        return Input::ESCAPE;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                return Input::ESCAPE;
            default:
                break;
        }
    }
    return Input::NO_INPUT;
}

void SDL::displayAll(std::vector<std::string> Pixels)
{
    clearScreen();
    for (unsigned int i = 0; i < Pixels.size(); i++) {
        for (unsigned int j = 1; j < Pixels.at(i).size(); j++) {
            SDL_Rect pixelRect = {static_cast<int>(j * 12), static_cast<int>(i * 12), 12, 12};
            switch (Pixels.at(i)[j]) {
                case 0:
                    SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
                    break;
                case 1:
                    SDL_SetRenderDrawColor(mainRenderer, 0, 255, 0, 255);
                    break;
                case 2:
                    SDL_SetRenderDrawColor(mainRenderer, 255, 0, 0, 255);
                    break;
                case 3:
                    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
                    break;
                case 4:
                    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
                    break;
            }

            SDL_RenderFillRect(mainRenderer, &pixelRect);
        }
    }
}

void SDL::displayLib(std::vector<std::string> lib, short highLight)
{
    clearScreen();
    SDL_Color textColor = {255, 255, 255};
    SDL_Color highLightColor = {255, 255, 0};

    int text_width;
    int text_height;
    int y = 10;

    for (int i = 0; i < lib.size(); i++) {
        SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect rect;

        if (i == highLight) {
            surface = TTF_RenderText_Solid(font, lib[i].c_str(), highLightColor);
        } else {
            surface = TTF_RenderText_Solid(font, lib[i].c_str(), textColor);
        }

        texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
        rect.x = 10;
        rect.y = y;
        rect.w = surface->w;
        rect.h = surface->h;

        SDL_RenderCopy(mainRenderer, texture, NULL, &rect);

        y += surface->h + 5;

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

void SDL::displayGame(std::vector<std::string> game, short highLight)
{
    clearScreen();
    SDL_Color textColor = {255, 255, 255};
    SDL_Color highLightColor = {255, 255, 0};

    int text_width;
    int text_height;
    int y = 10;

    for (int i = 0; i < game.size(); i++) {
        SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect rect;

        if (i == highLight) {
            surface = TTF_RenderText_Solid(font, game[i].c_str(), highLightColor);
        } else {
            surface = TTF_RenderText_Solid(font, game[i].c_str(), textColor);
        }

        texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
        rect.x = 10;
        rect.y = y;
        rect.w = surface->w;
        rect.h = surface->h;

        SDL_RenderCopy(mainRenderer, texture, NULL, &rect);

        y += surface->h + 5;

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

void SDL::displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) {}

void SDL::printRectangle(std::pair<unsigned int, unsigned int> pos) {}
