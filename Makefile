##
## EPITECH PROJECT, 2023
## SYN_abstractVM_$2023
## File description:
## Makefile
##

SRC	=	main.cpp	\
		Utils/Utils.cpp	\
		Ints/Int8/int8.cpp	\
		Ints/Int16/int16.cpp	\
		Ints/Int32/int32.cpp	\
		Ints/Float/FLOAT.cpp	\
		Ints/Double/DOUBLE.cpp	\
		IOperand/Factory/Factory.cpp	\
		Stack/Stack.cpp	\
		Parser/Parser.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	abstractVM

all:	$(NAME)

$(NAME):
		g++	-std=c++20	-c	$(SRC)
		g++	-std=c++20	$(SRC)	-o	$(NAME)

clean:
		rm	-rf	$(OBJ)
		rm	-rf	*.o
		rm	-rf	*~

fclean:	clean
		rm	-rf	$(NAME)

re:	fclean	all
