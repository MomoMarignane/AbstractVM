/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** int32.cpp
*/

#include "int32.hpp"

Operands::Int32::Int32(const std::string& value)
{
    valueInt_ = std::stoi(value);
    if (valueInt_ < (-2147483648)) {
        std::cout << "to small int32" << std::endl;
        exit(-1);
    }
    if (valueInt_ > 2147483647) {
        std::cout << "to long int32" << std::endl;
        exit(-1);
    }
    value_ = static_cast<int32_t>(valueInt_);
}

Operands::Int32::~Int32()
{}

Operands::eOperandType Operands::Int32::getType() const
{
    return eOperandType::INT32;
}

std::string Operands::Int32::toString() const
{
    return std::to_string(value_);
}

Operands::IOperand* Operands::Int32::operator+(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int32_t rhsValue = static_cast<int32_t>(std::stoi(rhs.toString()));

    int32_t result = value_ + rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int32::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int32_t rhsValue = static_cast<int32_t>(std::stoi(rhs.toString()));

    int32_t result = value_ - rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int32::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int32_t rhsValue = static_cast<int32_t>(std::stoi(rhs.toString()));

    int32_t result = value_ * rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int32::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int32_t rhsValue = static_cast<int32_t>(std::stoi(rhs.toString()));

    if (rhsValue == 0) {
        std::cout << "Division by zero" << std::endl;
        exit(-1);
    }

    int32_t result = value_ / rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int32::operator%(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int32_t rhsValue = static_cast<int32_t>(std::stoi(rhs.toString()));

    if (rhsValue == 0) {
        std::cout << "Modulo by zero" << std::endl;
        exit(-1);
    }

    int32_t result = value_ % rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}