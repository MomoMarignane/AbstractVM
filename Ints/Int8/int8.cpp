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
    if (valueInt_ < (-128))
    throw ERROR::MyException("to small int8: Ints/int8/int8.cpp: line 13");
    if (valueInt_ > 127)
        throw ERROR::MyException("to long int8: Ints/int8/int8.cpp: line 15");
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
    double rhsValue = static_cast<double>(std::stof(rhs.toString()));
    double result = value_ + rhsValue;
    if (result > 127 && tmpType == Operands::eOperandType::INT8)
        throw ERROR::MyException("Result is too long for int8: Ints/Int8/Int8.cpp: line 37");
    std::string resultString = std::to_string(result);
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));
    double result = value_ - rhsValue;
    if (result > 127 && tmpType == Operands::eOperandType::INT8)
        throw ERROR::MyException("Result is too long for int8: Ints/Int8/Int8.cpp: line 48");
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));
    double result = value_ * rhsValue;
    if (result > 127 && tmpType == Operands::eOperandType::INT8)
        throw ERROR::MyException("Result is too long for int8: Ints/Int8/Int8.cpp: line 62");
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = static_cast<double>(std::stoi(rhs.toString()));
    if (rhsValue == 0)
        throw ERROR::MyException("to small int8: Ints/int8/int8.cpp: line 68");
    double result = value_ / rhsValue;
    if (result > 127 && tmpType == Operands::eOperandType::INT8)
        throw ERROR::MyException("Result is too long for int8: Ints/Int8/Int8.cpp: line 74");
    std::string resultString = std::to_string(result);
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::Int8::operator%(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    int8_t rhsValue = static_cast<int8_t>(std::stoi(rhs.toString()));
    if (rhsValue == 0)
        throw ERROR::MyException("to small int8: Ints/int8/int8.cpp: line 80");
    int8_t result = value_ % rhsValue;
    if (result > 127 && tmpType == Operands::eOperandType::INT8)
        throw ERROR::MyException("Result is too long for int8: Ints/Int8/Int8.cpp: line 89");
    std::string resultString = std::to_string(result);
    return Operands::Factory::createOperand(tmpType, resultString);
}