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
    if (valueInt_ < (-32768)) {
        std::cout << "to small DOUBLE" << std::endl;
        exit(-1);
    }
    if (valueInt_ > 32767) {
        std::cout << "to long DOUBLE" << std::endl;
        exit(-1);
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
        std::cout << "Division by zero" << std::endl;
        exit(-1);
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
        std::cout << "Modulo by zero" << std::endl;
        exit(-1);
    }
    double result = std::fmod(value_, rhsValue); // Utilisation de fmod pour le modulo
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}