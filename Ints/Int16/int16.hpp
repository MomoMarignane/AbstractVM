/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** int16.hpp
*/

#pragma once
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include <cstdint>
    #include <string>
    #include "../../IOperand/Factory/Factory.hpp"
    #include "../../IOperand/IOperand.hpp"

namespace Operands {
    class Int16 : public IOperand
    {
        public:
            Int16(const std::string& value);
            ~Int16();

            eOperandType getType() const override;
            IOperand* operator+(const IOperand& rhs) const override;
            IOperand* operator-(const IOperand& rhs) const override;
            IOperand* operator*(const IOperand& rhs) const override;
            IOperand* operator/(const IOperand& rhs) const override;
            IOperand* operator%(const IOperand& rhs) const override;

            std::string toString() const override;

        private:
            int16_t value_;
            int valueInt_;
    };
}