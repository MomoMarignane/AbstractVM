/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Stack.cpp
*/

#include "Stack.hpp"

VM::Stack::Stack()
{
}

VM::Stack::~Stack()
{}

void VM::Stack::run(VM::Parser* p)
{
    parser_ = p;
    p->setCmd();
    if (parser_->getCmd() == VM::UserCmd::EXIT)
        exit(0);
    if (parser_->getCmd() == VM::UserCmd::PUSH)
        Push();
    if (parser_->getCmd() == VM::UserCmd::DUMP)
        Dump();
    if (parser_->getCmd() == VM::UserCmd::ASSERT)
        Assert();
    if (parser_->getCmd() == VM::UserCmd::POP)
        Pop();
    if (parser_->getCmd() == VM::UserCmd::CLEAR)
        Clear();
    if (parser_->getCmd() == VM::UserCmd::PRINT)
        this->Print();
}

void VM::Stack::Push()
{
    parser_->setTypeData();
    if (parser_->getTypeData() == Operands::eOperandType::NO_VALUE)
        throw ERROR::MyException("Error line 40: no type detected");
    Operands::IOperand* o = Operands::Factory::createOperand(parser_->getTypeData(), parser_->getValue());
    stack_.insert(stack_.begin(), o)
;    // stack_.push_back(std::make_pair(value, type));
    // if (stack_.empty())
    //     std::cout << "erreur lors du push" << std::endl;
}

void VM::Stack::Assert()
{
    // if (stack_.empty()) {
    //     std::cout << "Error: Stack is empty." << std::endl;
    //     exit(1);
    // }
    // const std::string& topValue = stack_.back().first;
    // const std::string& expectedValue = parser_->getValue();
    // if (topValue != expectedValue) {
    //     std::cout << "Error: Assert failed. Expected value: " << expectedValue << ", Actual value: " << topValue << std::endl;
    //     exit(1);
    // }
}

void VM::Stack::Dump()
{
    std::cout << "in dump" << std::endl;
    if (stack_.empty())
        exit(42);
    for (const auto& elem : stack_) {
        std::cout << elem->toString() << std::endl;
    }
}

void VM::Stack::Print()
{
    if (stack_.empty()) {
        std::cout << "Error: Stack is empty." << std::endl;
        exit(1);
    }
    if (std::stoi(stack_[0]->toString())) {
        std::cout << "int8 detected dans print" << std::endl;
        int asciiValue = std::stoi(stack_[0]->toString());
        char character = static_cast<char>(asciiValue);
        std::cout << "caracrete ascii -> " << static_cast<char>(asciiValue) << std::endl;
    } else {
        std::cout << "value begin stack -> " << stack_[0]->toString() << std::endl;
    }
    // std::cout << "Output: " << character << std::endl;
}

void VM::Stack::Clear()
{
    while (!stack_.empty())
        stack_.erase(stack_.begin());
}

void VM::Stack::Pop()
{
    if (stack_.empty()) {
        std::cout << "Error: Stack is empty." << std::endl;
        exit(1);
    }
    stack_.erase(stack_.begin());
}