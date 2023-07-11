/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Utils.cpp
*/

#include "Utils.hpp"

bool check_founded(size_t pos)
{
    if (pos == std::string::npos)
        return false;
    else
        return true;
}

std::string mySetPrecisionSpecialDecimal(size_t pos, std::string src)
{
    size_t i = 0;
    std::string tmp;
    while (src[i] != '.')
        tmp += src[i];
    while (i < 7) {
        if (i < (src.size() - 1))
            tmp += '0';
        else
            tmp += src[i];
    }
    return tmp;
}

std::string myDeletUnlessZero(std::string value)
{
    std::string valueStr_ = value;
    bool switch_ = false;
    int deleteZero = valueStr_.size() - 1;
    size_t pointPos;
    for (int i = 0; valueStr_[i]; i += 1) {
        if (valueStr_[i] == '.')
            switch_ = true;
            pointPos = i;
    }
    if (switch_ == true) {
        for (; deleteZero >= 0 && (valueStr_[deleteZero] == '0' || valueStr_[deleteZero] == '.'); deleteZero -= 1)
            if (valueStr_[deleteZero] == '.') {
                deleteZero -= 1;
                break;
            }
        std::string tmp;
        for (int c = 0; c <= deleteZero; c += 1)
            tmp += valueStr_[c];
        valueStr_ = tmp;
    }
    // for (int i = valueStr_.size() - 1; i < pointPos; i -= 1)

    return valueStr_;
}