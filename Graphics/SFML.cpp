/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Sfml
*/

#include "SFML.hpp"

extern "C" std::string libName()
{
    return "sfml";
}

extern "C" IRenderer *createLib()
{
    return new sfml();
}

extern "C" void destroyLib(IRenderer *lib)
{
    delete lib;
}

sfml::sfml() : videoMode(1920, 1080, 32), window(videoMode, "SFML window"), characterSize(20)
{
    font.loadFromFile("arial.ttf");
    refreshScreen();
}

sfml::~sfml()
{
    window.close();
    font.~Font();
}

Input sfml::getInput()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Z:
                    return Input::Z_KEY;
                case sf::Keyboard::S:
                    return Input::S_KEY;
                case sf::Keyboard::Q:
                    return Input::Q_KEY;
                case sf::Keyboard::D:
                    return Input::D_KEY;
                case sf::Keyboard::Right:
                    return Input::ENTER;
                case sf::Keyboard::Down:
                    return Input::DOWN_ARROW;
                case sf::Keyboard::Up:
                    return Input::UP_ARROW;
                case sf::Keyboard::Escape:
                    return Input::ESCAPE;
                default:
                    return Input::NO_INPUT;
            }
        }
    }
    return Input::NO_INPUT;
}

void sfml::displayAll(std::vector<std::string> Pixels)
{
    clearScreen();
    for (unsigned int i = 0; i < Pixels.size(); i++) {
        for (unsigned int j = 1; j < Pixels.at(i).size(); j++) {
            sf::RectangleShape pixel(sf::Vector2f(25, 25));
            pixel.setPosition(j * 25, i * 25);
            switch (Pixels.at(i)[j]) {
                case 0:
                    pixel.setFillColor(sf::Color::Black);
                    break;
                case 1:
                    pixel.setFillColor(sf::Color::Green);
                    break;
                case 2:
                    pixel.setFillColor(sf::Color::Red);
                    break;
                case 3:
                    pixel.setFillColor(sf::Color::White);
                    break;
                case 4:
                    pixel.setFillColor(sf::Color::White);
                    break;
            }
            window.draw(pixel);
        }
    }
}

void sfml::refreshScreen() 
{
    window.display();
}

void sfml::clearScreen()
{
    window.clear();
}

void sfml::displayLib(std::vector<std::string> lib, short highLight)
{
    clearScreen();
    sf::Color textColor = sf::Color::White;
    sf::Color highLightColor = sf::Color::Yellow;

    int text_width;
    int text_height;
    int y = 10;

    for (int i = 0; i < lib.size(); i++) {
        sf::Text text(lib[i], font, characterSize);
        if (i == highLight) {
            text.setFillColor(highLightColor);
        } else {
            text.setFillColor(textColor);
        }

        text_width = text.getLocalBounds().width;
        text_height = text.getLocalBounds().height;
        text.setPosition(5, y);

        window.draw(text);

        y += text_height + 5;
    }
}

void sfml::displayGame(std::vector<std::string> game, short highLight)
{
    clearScreen();
    sf::Color textColor = sf::Color::White;
    sf::Color highLightColor = sf::Color::Yellow;

    int text_width;
    int text_height;
    int y = 10;

    for (int i = 0; i < game.size(); i++) {
        sf::Text text(game[i], font, characterSize);
        if (i == highLight) {
            text.setFillColor(highLightColor);
        } else {
            text.setFillColor(textColor);
        }

        text_width = text.getLocalBounds().width;
        text_height = text.getLocalBounds().height;
        text.setPosition(5, y);

        window.draw(text);

        y += text_height + 5;
    }
}

void sfml::displayScore(std::pair<unsigned int, unsigned int> pos, unsigned int score) {}

void sfml::printRectangle(std::pair<unsigned int, unsigned int> pos) {}

