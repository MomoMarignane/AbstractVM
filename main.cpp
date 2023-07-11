/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** main.cpp
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utils/Utils.hpp"
#include "Parser/Parser.hpp"
#include "IOperand/IOperand.hpp"
#include "IOperand/Factory/Factory.hpp"
#include "Stack/Stack.hpp"

int VMfunc(char *src)
{
    VM::Stack s;
    try {
        std::ifstream file(src);
        if (!file.is_open())
            throw ERROR::MyException("open file: main.cpp: line 21");
        std::string input;
        while (std::getline(file, input)) {
            VM::Parser p(input + '\n');
            s.run(&p);
        }
    } catch (const ERROR::MyException& e) {
        throw ERROR::MyException("main.cpp: line 29");
        s.Clear();
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2) {
        std::cout << "Error: nb args not valid: main.cpp: line 40" << std::endl;
        return 84;
    }
    try {
        VMfunc(av[1]);
    } catch (const ERROR::MyException& e) {
        return 84;
    }
    return 0;
}