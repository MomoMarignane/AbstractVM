/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** FLOAT.hpp
*/

#pragma once
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include <cstdint>
    #include <string>
    #include <iomanip>
    #include "../../IOperand/IOperand.hpp"
    #include "../../IOperand/Factory/Factory.hpp"

namespace Operands {
    class FLOAT : public IOperand
    {
        public:
            FLOAT(const std::string& value);
            ~FLOAT();

            eOperandType getType() const override;
            IOperand* operator+(const IOperand& rhs) const override;
            IOperand* operator-(const IOperand& rhs) const override;
            IOperand* operator*(const IOperand& rhs) const override;
            IOperand* operator/(const IOperand& rhs) const override;
            IOperand* operator%(const IOperand& rhs) const override;

            std::string toString() const override;

        private:
            float value_;
            float valueInt_;
    };
}