/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** int8.hpp
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
    class Int8 : public IOperand
    {
        public:
            Int8(const std::string& value);
            ~Int8();

            eOperandType getType() const override;
            IOperand* operator+(const IOperand& rhs) const override;
            IOperand* operator-(const IOperand& rhs) const override;
            IOperand* operator*(const IOperand& rhs) const override;
            IOperand* operator/(const IOperand& rhs) const override;
            IOperand* operator%(const IOperand& rhs) const override;

            std::string toString() const override;

        private:
            int8_t value_;
            int valueInt_;
    };
}