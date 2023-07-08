/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** IOperand.hpp
*/

#pragma once
    #include "../Utils/Utils.hpp"
    #include "../Error/Error.hpp"

namespace Operands {
    class IOperand
        {
            public:
                virtual ~IOperand () {}
                virtual std::string toString() const = 0; //string that represents the instance
                virtual eOperandType getType() const = 0; //returns the type of instance
                virtual IOperand* operator+(const IOperand &) const = 0; //sum
                virtual IOperand* operator-(const IOperand &) const = 0; //diff
                virtual IOperand* operator*(const IOperand &) const = 0; //mul
                virtual IOperand* operator/(const IOperand &) const = 0; //div
                virtual IOperand* operator%(const IOperand &) const = 0; //mod
        };
}