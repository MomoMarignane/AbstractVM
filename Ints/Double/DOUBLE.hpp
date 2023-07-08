/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** DOUBLE.hpp
*/

#pragma once
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include <cstdint>
    #include <string>
    #include "../../IOperand/IOperand.hpp"
    #include "../../IOperand/Factory/Factory.hpp"

namespace Operands {
    class DOUBLE : public IOperand
    {
        public:
            DOUBLE(const std::string& value);
            ~DOUBLE();

            eOperandType getType() const override;
            IOperand* operator+(const IOperand& rhs) const override;
            IOperand* operator-(const IOperand& rhs) const override;
            IOperand* operator*(const IOperand& rhs) const override;
            IOperand* operator/(const IOperand& rhs) const override;
            IOperand* operator%(const IOperand& rhs) const override;

            std::string toString() const override;

        private:
            double value_;
            int valueInt_;
    };
}