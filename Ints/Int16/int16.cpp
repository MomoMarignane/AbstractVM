/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** int16.cpp
*/

#include "int16.hpp"

Operands::Int16::Int16(const std::string& value)
{
    if (value.size() >= 19) {
        throw ERROR::MyException("to long int16: Ints/int16/int16.cpp: line 12");
    }
    int64_t tmp = std::stol(value);
    if (tmp < (-32768))
        throw ERROR::MyException("to small int16: Ints/int16/int16.cpp: line 16");
    if (tmp > 32767)
        throw ERROR::MyException("to long int16: Ints/int16/int16.cpp: line 18");
    valueInt_ = std::stoi(value);
    value_ = static_cast<double>(valueInt_);
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
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));

    double result = value_ + rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));

    double result = value_ - rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));

    double result = value_ * rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));

    if (rhsValue == 0) {
        throw ERROR::MyException("division by 0: Ints/int16/int16.cpp: line 71");
    }

    double result = value_ / rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int16::operator%(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int16_t rhsValue = static_cast<int16_t>(std::stoi(rhs.toString()));

    if (rhsValue == 0) {
        throw ERROR::MyException("modulo by 0: Ints/int16/int16.cpp: line 86");
    }

    int16_t result = value_ % rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}