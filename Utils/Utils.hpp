/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Utils.hpp
*/

#pragma once
    #include <iostream>

namespace Operands {
    enum class eOperandType {
        NO_VALUE = 0,
        INT8 = 1,
        INT16 = 2,
        INT32 = 4,
        FLOAT = 8,
        DOUBLE = 16
    };
}

bool check_founded(size_t);