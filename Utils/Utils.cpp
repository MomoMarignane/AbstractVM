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