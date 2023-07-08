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