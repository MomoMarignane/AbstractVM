/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** FLOAT.cpp
*/

#include "FLOAT.hpp"

Operands::FLOAT::FLOAT(const std::string& value)
{
    valueInt_ = std::stof(value);
    if (valueInt_ < (-32768)) {
        std::cout << "to small FLOAT" << std::endl;
        exit(-1);
    }
    if (valueInt_ > 32767) {
        std::cout << "to long FLOAT" << std::endl;
        exit(-1);
    }
    value_ = std::stof(value);
    // value_ = static_cast<float>(std::stoi(value));

}

Operands::FLOAT::~FLOAT()
{}

Operands::eOperandType Operands::FLOAT::getType() const
{
    return eOperandType::FLOAT;
}

std::string Operands::FLOAT::toString() const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value_;
    return ss.str();
}

Operands::IOperand* Operands::FLOAT::operator+(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    float rhsValue = std::stof(rhs.toString());
    float result = value_ + rhsValue;
    // Convertir le résultat en chaîne de caractères avec la précision souhaitée
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << result;
    std::string resultString = ss.str();
    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::FLOAT::operator-(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    float rhsValue = std::stof(rhs.toString());

    float result = value_ - rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::FLOAT::operator*(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    float rhsValue = std::stof(rhs.toString());

    float result = value_ * rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::FLOAT::operator/(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    float rhsValue = std::stof(rhs.toString());

    if (rhsValue == 0) {
        std::cout << "Division by zero" << std::endl;
        exit(-1);
    }

    float result = value_ / rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::FLOAT::operator%(const IOperand& rhs) const
{
    std::cout << "Modulo operation not supported for FLOAT" << std::endl;
    exit(-1);
    return nullptr;
}