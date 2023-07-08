/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Factory.hpp
*/

#pragma once
    #include "../IOperand.hpp"
    #include "../../Ints/Int8/int8.hpp"
    #include "../../Ints/Int16/int16.hpp"
    #include "../../Ints/Int32/int32.hpp"
    #include "../../Ints/Float/FLOAT.hpp"
    #include "../../Ints/Double/DOUBLE.hpp"

namespace Operands {
    class Factory : public Operands::IOperand {
        public:
            Factory();
            static IOperand* createOperand(eOperandType type, const std::string &value);
            static IOperand* createInt8(const std::string& value);
            static IOperand* createInt16(const std::string& value);
            static IOperand* createInt32(const std::string& value);
            static IOperand* createFloat(const std::string& value);
            static IOperand* createDouble(const std::string& value);
    };
}