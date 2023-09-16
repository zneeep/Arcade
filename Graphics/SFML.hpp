/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "IRenderer.hpp"
#include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>

class sfml : public IRenderer {
    public:
        sfml();
        ~sfml();
        Input getInput() override;
        void displayAll(std::vector<std::string> Pixels) override;
        void refreshScreen() override;
        void clearScreen() override;
        void displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) override;
        void displayLib(std::vector<std::string> lib, short hightlight) override;
        void displayGame(std::vector<std::string> game, short hightlight) override;
        void printRectangle(std::pair<unsigned int, unsigned int> pos) override;

        sf::VideoMode videoMode;
        sf::RenderWindow window;
        sf::RenderWindow mainWindow;
        sf::RenderWindow scoreWindow;
        sf::Font font;
        unsigned int characterSize;
};

extern "C" std::string libName();
extern "C" IRenderer *createLib();
extern "C" void destroyLib(IRenderer *lib);

#endif /* !SFML_HPP_ */
