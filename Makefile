# Program Executable
EXE			:=	abstract_data

# Files
SRC			:=	src/main.cpp \

# Variables
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98 -Iincludes -O2 -g3

# Makefile
all			:	${EXE}

${EXE}		:	${SRC}
				${CC} ${CFLAGS} ${SRC} -o ${EXE}

clean		:
				rm -rf ${EXE}

re			:	clean all

.PHONY		:	all clean re
