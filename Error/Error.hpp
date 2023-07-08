/*
** EPITECH PROJECT, 2023
** B-SYN-400-MAR-4-1-abstractVM-mohamed.mansour
** File description:
** Error.hpp
*/

#pragma once
    #include <iostream>
    #include <exception>

namespace ERROR {
    class MyException : public std::exception {
        public:
            MyException(const std::string& message) : message_(message) {
                std::cout << message_ << std::endl;
            }

            // Override the what() function to provide a custom error message
            const char* what() const noexcept override {
                return message_.c_str();
            }

    private:
        std::string message_;
    };
}