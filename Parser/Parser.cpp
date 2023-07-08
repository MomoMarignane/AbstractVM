/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

VM::Parser::Parser(std::string src)
{
    typeData_ = Operands::eOperandType::NO_VALUE;
    currentCmd_ = VM::UserCmd::NO_FOUND;
    for (int i = 0; src[i]; i += 1) {
        if (src[i] == ';')
            break;
        fullLineCmd_ += src[i];
    }
}

VM::Parser::~Parser()
{}


VM::UserCmd VM::Parser::searchInString()
{
    if (fullLineCmd_.size() == 0)
        currentCmd_ = VM::UserCmd::NO_FOUND;
    size_t pos = fullLineCmd_.find("push");
    if (check_founded(pos) == true && pos == 0) {
        std::cout << "push ok." << std::endl;
        return VM::UserCmd::PUSH;
    }
    pos = fullLineCmd_.find("pop");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::POP;
    pos = fullLineCmd_.find("clear");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::CLEAR;
    pos = fullLineCmd_.find("dup");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::DUP;
    pos = fullLineCmd_.find("swap");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::SWAP;
    pos = fullLineCmd_.find("dump");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::DUMP;
    pos = fullLineCmd_.find("assert");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::ASSERT;
    pos = fullLineCmd_.find("add");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::ADD;
    pos = fullLineCmd_.find("sub");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::SUB;
    pos = fullLineCmd_.find("mul");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::MUL;
    pos = fullLineCmd_.find("div");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::DIV;
    pos = fullLineCmd_.find("mod");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::MOD;
    pos = fullLineCmd_.find("load");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::LOAD;
    pos = fullLineCmd_.find("store");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::STORE;
    pos = fullLineCmd_.find("print");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::PRINT;
    pos = fullLineCmd_.find("exit");
    if (check_founded(pos) == true && pos == 0)
        return VM::UserCmd::EXIT;
    return VM::UserCmd::NO_FOUND;
}

void VM::Parser::setTypeData()
{
    size_t pos = fullLineCmd_.find("int8");
    int result = 0;
    if (check_founded(pos) == true) {
        typeData_ = Operands::eOperandType::INT8;
        result += 1;
    }
    pos = fullLineCmd_.find("int16");
    if (check_founded(pos) == true) {
        typeData_ = Operands::eOperandType::INT16;
        result += 1;
    }
    pos = fullLineCmd_.find("int32");
    if (check_founded(pos) == true) {
        typeData_ = Operands::eOperandType::INT32;
        result += 1;
    }
    pos = fullLineCmd_.find("float");
    if (check_founded(pos) == true) {
        typeData_ = Operands::eOperandType::FLOAT;
        result += 1;
    }
    pos = fullLineCmd_.find("double");
    if (check_founded(pos) == true) {
        typeData_ = Operands::eOperandType::DOUBLE;
        result += 1;
    }
    if (result > 2)
        exit(-1);
}

void VM::Parser::setCmd()
{
    currentCmd_ = searchInString();
    switch (currentCmd_) {
        case VM::UserCmd::PUSH :
            setValue();
            setTypeData();
            break;
        case VM::UserCmd::POP :
            break;
        case VM::UserCmd::CLEAR :
            break;
        case VM::UserCmd::DUP :
            break;
        case VM::UserCmd::SWAP :
            break;
        case VM::UserCmd::DUMP :
            break;
        case VM::UserCmd::ASSERT :
            setValue();
            setTypeData();
            break;
        case VM::UserCmd::ADD :
            break;
        case VM::UserCmd::SUB :
            break;
        case VM::UserCmd::MUL :
            break;
        case VM::UserCmd::DIV :
            break;
        case VM::UserCmd::MOD :
            break;
        case VM::UserCmd::LOAD :
            setValue();
            setTypeData();
            break;
        case VM::UserCmd::STORE :
            setValue();
            setTypeData();
            break;
        case VM::UserCmd::PRINT :
            break;
        case VM::UserCmd::EXIT :
            break;
        default:
            exit(-1);
    }
    return;
}

VM::UserCmd VM::Parser::getCmd() const
{
    return currentCmd_;
}

void VM::Parser::setValue()
{
    value_ = "";
    bool catch_ = false;
    for (int i = 0, j = 0; fullLineCmd_[i]; i += 1) {
        if (fullLineCmd_[i] == ')')
            break;
        if (catch_ == true && fullLineCmd_[i] >= '0' && fullLineCmd_[i] <= '9')
            value_ += fullLineCmd_[i];
        if (fullLineCmd_[i] == '(')
            catch_ = true;
    }
    std::cout << "enregistrer en tent que [" << value_ << "]" << std::endl;
}

std::string VM::Parser::getValue() const
{
    return value_;
}

std::string VM::Parser::getFullLine() const
{
    return fullLineCmd_;
}

Operands::eOperandType VM::Parser::getTypeData() const
{
    return typeData_;
}