/*
** EPITECH PROJECT, 2023
** SYN_abstractVM_$2023
** File description:
** Stack.hpp
*/

#pragma once
    #include "../Parser/Parser.hpp"
    #include "../IOperand/Factory/Factory.hpp"

namespace VM {
    class Stack {
        public:
            Stack();
            ~Stack();
            void run(VM::Parser*);
            void Push();
            void Pop();
            void Clear();
            void Dup() {};
            void Swap() {};
            void Dump();
            void Assert();
            void Add() {};
            void Sub() {};
            void Mul() {};
            void Load() {};
            void Store() {};
            void Print();
            void Exit() {};
        private:
            std::vector<Operands::IOperand*> stack_;
            VM::Parser* parser_;
            Operands::IOperand* factory_;
    };
}