#Executable names:
EXE =
TEST = test main

#Add all object files needed for compiling:
EXE_OBJ = main.o tests.o
OBJS = matrix.o

#Generated files

#Use the cs225 makefile template:
include cs225/make/cs225.mk