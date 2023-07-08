/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Parser.hpp
*/

#pragma once
    #include <iostream>
    #include <string>
    #include <utility>
    #include <vector>
    #include "../Utils/Utils.hpp"

namespace VM {
    enum class UserCmd {
        COMMENTS,
        PUSH,
        POP,
        CLEAR,
        DUP,
        SWAP,
        DUMP,
        ASSERT,
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        LOAD,
        STORE,
        PRINT,
        EXIT,
        NO_FOUND
    };
}

namespace VM {
    class Parser {
        public:
            Parser(std::string);
            ~Parser();
            VM::UserCmd searchInString();
            void setCmd();
            void setValue();
            void setTypeData();
            std::string getFullLine() const;
            VM::UserCmd getCmd() const;
            std::string getValue() const;
            Operands::eOperandType getTypeData() const;
        private:
            std::string fullLineCmd_;
            VM::UserCmd currentCmd_;
            std::string value_;
            Operands::eOperandType typeData_;
    };
}