/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** int16.cpp
*/

#include "int16.hpp"

Operands::Int16::Int16(const std::string& value)
{
    valueInt_ = std::stoi(value);
    if (valueInt_ < (-32768)) {
        std::cout << "to small int16" << std::endl;
        exit(-1);
    }
    if (valueInt_ > 32767) {
        std::cout << "to long int16" << std::endl;
        exit(-1);
    }
    value_ = static_cast<int16_t>(valueInt_);
}

Operands::Int16::~Int16()
{}

Operands::eOperandType Operands::Int16::getType() const
{
    return eOperandType::INT16;
}

std::string Operands::Int16::toString() const
{
    return std::to_string(value_);
}

Operands::IOperand* Operands::Int16::operator+(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int16_t rhsValue = static_cast<int16_t>(std::stoi(rhs.toString()));

    int16_t result = value_ + rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int16_t rhsValue = static_cast<int16_t>(std::stoi(rhs.toString()));

    int16_t result = value_ - rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int16_t rhsValue = static_cast<int16_t>(std::stoi(rhs.toString()));

    int16_t result = value_ * rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int16_t rhsValue = static_cast<int16_t>(std::stoi(rhs.toString()));

    if (rhsValue == 0) {
        std::cout << "Division by zero" << std::endl;
        exit(-1);
    }

    int16_t result = value_ / rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator%(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int16_t rhsValue = static_cast<int16_t>(std::stoi(rhs.toString()));

    if (rhsValue == 0) {
        std::cout << "Modulo by zero" << std::endl;
        exit(-1);
    }

    int16_t result = value_ % rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}