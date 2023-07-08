/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** int8.cpp
*/

#include "int8.hpp"

Operands::Int8::Int8(const std::string& value)
{
    valueInt_ = std::stoi(value);
    if (valueInt_ < (-128)) {
        std::cout << "to small int8" << std::endl;
        exit(-1);
    }
    if (valueInt_ > 127) {
        std::cout << "to long int8" << std::endl;
        exit(-1);
    }
    value_ = static_cast<int8_t>(valueInt_);
}

Operands::Int8::~Int8()
{}

Operands::eOperandType Operands::Int8::getType() const
{
    return eOperandType::INT8;
}

std::string Operands::Int8::toString() const
{
    return std::to_string(value_);
}

Operands::IOperand* Operands::Int8::operator+(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int8_t rhsValue = static_cast<int8_t>(std::stoi(rhs.toString()));
    int8_t result = value_ + rhsValue;
    std::string resultString = std::to_string(result);
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int8_t rhsValue = static_cast<int8_t>(std::stoi(rhs.toString()));

    int8_t result = value_ - rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int8_t rhsValue = static_cast<int8_t>(std::stoi(rhs.toString()));

    int8_t result = value_ * rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int8_t rhsValue = static_cast<int8_t>(std::stoi(rhs.toString()));
    if (rhsValue == 0) {
        std::cout << "Division by zero" << std::endl;
        exit(-1);
    }
    int8_t result = value_ / rhsValue;
    std::string resultString = std::to_string(result);
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator%(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int8_t rhsValue = static_cast<int8_t>(std::stoi(rhs.toString()));
    if (rhsValue == 0) {
        std::cout << "Modulo by zero" << std::endl;
        exit(-1);
    }
    int8_t result = value_ % rhsValue;
    std::string resultString = std::to_string(result);
    return Operands::Factory::createOperand(tmpType, resultString);
}