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
    fullLine_ = parser_->getFullLine();
    p->setCmd();
    // if (parser_->getCmd() == VM::UserCmd::EXIT)
    //     exit(0);
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
    if (parser_->getCmd() == VM::UserCmd::DUP)
        Dup();
    if (parser_->getCmd() == VM::UserCmd::SWAP)
        Swap();
    if (parser_->getCmd() == VM::UserCmd::STORE)
        Store();
    if (parser_->getCmd() == VM::UserCmd::LOAD)
        Load();
    if (parser_->getCmd() == VM::UserCmd::ADD)
        Add();
    if (parser_->getCmd() == VM::UserCmd::SUB)
        Sub();
    if (parser_->getCmd() == VM::UserCmd::MUL)
        Mul();
    if (parser_->getCmd() == VM::UserCmd::DIV)
        Div();
    if (parser_->getCmd() == VM::UserCmd::MOD)
        Mod();
}

void VM::Stack::Push()
{
    parser_->setTypeData();
    if (parser_->getTypeData() == Operands::eOperandType::NO_VALUE)
        throw ERROR::MyException("no type detected: Stack/Stack.cpp: line 40");
    Operands::IOperand* o = Operands::Factory::createOperand(parser_->getTypeData(), parser_->getValue());
    stack_.insert(stack_.begin(), o);
}

void VM::Stack::Assert()
{
    if (stack_.empty())
        throw ERROR::MyException("stack is empty: Stack/Stack.cpp: line 59");
    if (parser_->getValue() != stack_.front()->toString())
        throw ERROR::MyException("stack and value are not twin's: Stack/Stack.cpp: line 61");
}

void VM::Stack::Dup()
{
    if (stack_.empty())
        throw ERROR::MyException("stack is empty: Stack/Stack.cpp: line 73");
    Operands::IOperand* t = stack_.front();
    stack_.insert(stack_.begin(), t);
}

void VM::Stack::Dump()
{
    // std::cout << "in dump" << std::endl;
    if (stack_.empty())
        return;
    for (const auto& elem : stack_) {
        std::cout << elem->toString() << std::endl;
    }
}

void VM::Stack::Print()
{
    if (stack_.empty())
        throw ERROR::MyException("stack is empty: Stack/Stack.cpp: line 93");
    if (stack_.front()->getType() != Operands::eOperandType::INT8) {
        throw ERROR::MyException("value is not int8_t type: Stack/Stack.cpp: line 95");
    }
    int asciiValue = std::stoi(stack_.front()->toString());
    std::cout << static_cast<char>(asciiValue) << std::endl;
}

void VM::Stack::Clear()
{
    if (!stack_.empty())
        stack_.clear();
    if (!newStack_.empty())
        newStack_.clear();
}

void VM::Stack::Pop()
{
    if (stack_.empty())
        throw ERROR::MyException("stack is empty: Stack/Stack.cpp: line 112");
    stack_.erase(stack_.begin());
}

void VM::Stack::Swap()
{
    if (stack_.size() < 2) {
        throw ERROR::MyException("stack size too short: Stack/Stack.cpp: line 118");
    }
    Operands::IOperand* a;
    a = stack_[1];
    stack_[1] = stack_.front();
    stack_.front() = a;
}

void VM::Stack::Store()
{
    if (stack_.empty())
        throw ERROR::MyException("Stack is empty: Stack/Stack.cpp: line 134");
    if (std::stoi(parser_->getValue()) >= newStack_.size())
        newStack_.resize(std::stoi(parser_->getValue()) + 1, nullptr);
    newStack_[std::stoi(parser_->getValue())] = stack_.front();
    stack_.erase(stack_.begin());
    // std::cout << "value at index " << std::stoi(parser_->getValue()) << ": " << newStack_[std::stoi(parser_->getValue())]->toString() << std::endl;
}

void VM::Stack::Load()
{
    if (newStack_.size() < std::stoi(parser_->getValue()) || newStack_[std::stoi(parser_->getValue())] == nullptr)
        throw ERROR::MyException("newStack v is empty: Stack/Stack.cpp: line 145");
    Operands::IOperand* o = newStack_[std::stoi(parser_->getValue())];
    stack_.insert(stack_.begin(), newStack_[std::stoi(parser_->getValue())]);
    newStack_[std::stoi(parser_->getValue())] = nullptr;
}

void VM::Stack::Add()
{
    if (stack_.size() < 2)
        throw ERROR::MyException("Add: stack size < 2: Stack/Stack.cpp: line 154");
    Operands::IOperand* result = *stack_[1] + *stack_[0];
    for (int i = 0; i < 2; i += 1)
        stack_.erase(stack_.begin());
    stack_.insert(stack_.begin(), result);
}

void VM::Stack::Sub()
{
    if (stack_.size() < 2)
        throw ERROR::MyException("Sub: stack size < 2: Stack/Stack.cpp: line 165");
    Operands::IOperand* result = *stack_[1] - *stack_[0];
    for (int i = 0; i < 2; i += 1)
        stack_.erase(stack_.begin());
    stack_.insert(stack_.begin(), result);
}

void VM::Stack::Mul()
{
    if (stack_.size() < 2)
        throw ERROR::MyException("Sub: stack size < 2: Stack/Stack.cpp: line 165");
    Operands::IOperand* result = *stack_[1] * *stack_[0];
    for (int i = 0; i < 2; i += 1)
        stack_.erase(stack_.begin());
    stack_.insert(stack_.begin(), result);
}

void VM::Stack::Div()
{
    if (stack_.size() < 2)
        throw ERROR::MyException("Sub: stack size < 2: Stack/Stack.cpp: line 165");
    Operands::IOperand* result = *stack_[1] / *stack_[0];
    for (int i = 0; i < 2; i += 1)
        stack_.erase(stack_.begin());
    stack_.insert(stack_.begin(), result);
}

void VM::Stack::Mod()
{
    if (stack_.size() < 2)
        throw ERROR::MyException("Sub: stack size < 2: Stack/Stack.cpp: line 165");
    Operands::IOperand* result = *stack_[1] % *stack_[0];
    for (int i = 0; i < 2; i += 1)
        stack_.erase(stack_.begin());
    stack_.insert(stack_.begin(), result);
}