/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-lucas.siraux
** File description:
** Main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "missing argument" << std::endl;
        exit(84);
    }
    std::string str(av[1]);
    core b(str);
    
    b.coreLoop();
}