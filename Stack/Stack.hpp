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
            std::string getFullLine() const;
            void run(VM::Parser*);
            void Push();
            void Pop();
            void Clear();
            void Dup();
            void Swap();
            void Dump();
            void Assert();
            void Add();
            void Sub();
            void Mul();
            void Load();
            void Store();
            void Print();
            void Div();
            void Mod();
        private:
            std::vector<Operands::IOperand*> stack_;
            std::vector<Operands::IOperand*> newStack_;
            VM::Parser* parser_;
            Operands::IOperand* factory_;
            std::string fullLine_;
    };
}