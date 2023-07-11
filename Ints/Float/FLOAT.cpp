/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** FLOAT.cpp
*/

#include "FLOAT.hpp"

Operands::FLOAT::FLOAT(const std::string& value)
{
    int64_t tmp = std::stol(value);
    if (tmp < (-3.4e38f)) {
        throw ERROR::MyException("to small float: Ints/Float/FLOAT.cpp: line 13");
    }
    if (tmp > 3.4e38f) {
        throw ERROR::MyException("to long float: Ints/Float/FLOAT.cpp: line 15");
    }
    value_ = std::stof(value);
    valueInt_ = std::stof(value);
    valueStr_ = myDeletUnlessZero(value);
    // std::cout << "valueStr in constructeur -> " << valueStr_ << std::endl;
    // std::cout << "value_ sended --> " << value << std::endl;
    // std::cout << "value_ stocked --> " << value_ << std::endl;

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
    // std::stringstream ss;
    // ss << std::fixed << std::setprecision(2) << value_;
    // std::cout << "ss = " << ss.str() << std::endl;
    // return ss.str();
    // std::cout << "Dans toString FLOAT = " << valueStr_ << std::endl;
    return (valueStr_);
}

Operands::IOperand* Operands::FLOAT::operator+(const IOperand& rhs) const
{
    eOperandType tmpType = std::max(getType(), rhs.getType());
    float rhsValue = std::stof(rhs.toString());

    float result = value_ + rhsValue;
    return Operands::Factory::createOperand(tmpType, std::to_string(result));
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
        throw ERROR::MyException("division by 0: Ints/Float/FLOAT.cpp: line 77");
    }

    float result = value_ / rhsValue;
    std::string resultString = std::to_string(result);

    return Operands::Factory::createOperand(tmpType, resultString);
}

Operands::IOperand* Operands::FLOAT::operator%(const IOperand& rhs) const
{
    throw ERROR::MyException("modulo with float value: Ints/Float/FLOAT.cpp: line 13");
    return nullptr;
}