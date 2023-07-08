/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** DOUBLE.cpp
*/

#include "DOUBLE.hpp"

Operands::DOUBLE::DOUBLE(const std::string& value)
{
    valueInt_ = std::stoi(value);
    if (valueInt_ < (-32768))
        throw ERROR::MyException("to small DOUBLE: line 13: Ints/Double/DOUBLE.cpp");
    if (valueInt_ > 32767) {
        throw ERROR::MyException("to long DOUBLE: line 15: Ints/Double/DOUBLE.cpp");
    }
    value_ = static_cast<double>(valueInt_);
}

Operands::DOUBLE::~DOUBLE()
{}

Operands::eOperandType Operands::DOUBLE::getType() const
{
    return eOperandType::DOUBLE;
}

std::string Operands::DOUBLE::toString() const
{
    return std::to_string(value_);
}

Operands::IOperand* Operands::DOUBLE::operator+(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = std::stod(rhs.toString());
    double result = value_ + rhsValue;
    std::string resultString = std::to_string(result);
    // Utilisez une classe Factory pour créer un nouvel objet d'opérande approprié en fonction du type
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::DOUBLE::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = std::stod(rhs.toString());
    double result = value_ - rhsValue;
    std::string resultString = std::to_string(result);
    // Utilisez une classe Factory pour créer un nouvel objet d'opérande approprié en fonction du type
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::DOUBLE::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = std::stod(rhs.toString());
    double result = value_ * rhsValue;
    std::string resultString = std::to_string(result);
    // Utilisez une classe Factory pour créer un nouvel objet d'opérande approprié en fonction du type
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::DOUBLE::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = std::stod(rhs.toString());

    if (rhsValue == 0.0) {
        throw ERROR::MyException("division by 0: line 73: Ints/Double/DOUBLE.cpp");
    }

    double result = value_ / rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::DOUBLE::operator%(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    double rhsValue = std::stod(rhs.toString());
    if (rhsValue == 0) {
        throw ERROR::MyException("division by 0: line 73: Ints/Double/DOUBLE.cpp");
    }
    double result = std::fmod(value_, rhsValue); // Utilisation de fmod pour le modulo
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}