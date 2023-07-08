/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** main.cpp
*/

#include <iostream>
#include <iomanip>
#include "Utils/Utils.hpp"
#include "Parser/Parser.hpp"
#include "IOperand/IOperand.hpp"
#include "IOperand/Factory/Factory.hpp"
#include "Stack/Stack.hpp"

void VMfunc()
{
    std::string input;
    VM::Stack s;
    while (std::getline(std::cin, input)) {
        VM::Parser p(input);
        s.run(&p);
    }
}

int main(void)
{
    // Operands::IOperand* op1 = Operands::Factory::createOperand(Operands::eOperandType::INT8, "5");
    // Operands::IOperand* op2 = Operands::Factory::createOperand(Operands::eOperandType::FLOAT, "6.5");
    // Operands::IOperand* result = *op1 + *op2;
    // std::cout << "Addition result: " << result->toString() << std::endl;
    // delete result;
    try {
        VMfunc();
    } catch (const ERROR::MyException& e) {
        return 84;
    }
    return 0;
}