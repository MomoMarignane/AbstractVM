/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

Operands::Factory::Factory()
{}

Operands::IOperand* Operands::Factory::createOperand(eOperandType type, const std::string &value)
{
    if (type == eOperandType::INT8)
        return createInt8(value);
    if (type == eOperandType::INT16)
        return createInt16(value);
    if (type == eOperandType::INT32)
        return createInt32(value);
    if (type == eOperandType::FLOAT)
        return createFloat(value);
    if (type == eOperandType::DOUBLE)
        return createDouble(value);
    return nullptr;
}

Operands::IOperand* Operands::Factory::createInt8(const std::string& value)
{
    Operands::IOperand *newOperand = new Operands::Int8(value);
    return newOperand;
}

Operands::IOperand* Operands::Factory::createInt16(const std::string& value)
{
    Operands::IOperand *newOperand = new Operands::Int16(value);
    return newOperand;
}

Operands::IOperand* Operands::Factory::createInt32(const std::string& value)
{
    Operands::IOperand *newOperand = new Operands::Int32(value);
    return newOperand;
}

Operands::IOperand* Operands::Factory::createFloat(const std::string& value)
{
    // std::cout << "value sended into float class --> " << value << std::endl;
    // std::stringstream ss;
    // ss << std::fixed << std::setprecision(7) << value;
    // std::cout << "ss = " << ss.str() << std::endl;
    // bool precSig = false;
    // size_t precision;
    // for (int i = 0; value[i]; i += 1) {
    //     if (precSig)
    //         precision += 1;
    //     if (value[i] == '.')
    //         precSig = true;
    // }
    // // std::cout << "value sended into float class --> " << value << std::endl;
    // std::stringstream ss;
    // ss << std::fixed << std::setprecision(precision) << value;
    // // std::cout << "ss = " << ss.str() << std::endl;
    // Operands::IOperand *newOperand = new Operands::Int32(ss.str());
    // return newOperand;
    // std::cout << "VALUE ICI LA LA = " << value << std::endl;
    std::string valueStr_ = myDeletUnlessZero(value);
    return new Operands::FLOAT(valueStr_);
}

Operands::IOperand* Operands::Factory::createDouble(const std::string& value)
{
    Operands::IOperand *newOperand = new Operands::DOUBLE(value);
    return newOperand;
}