# MAKEFILE for compiling fraction class test

COMPILE = g++ -Wall -Wextra -pedantic -std=c++17 -g
EXEC = TestFractionClass
LIBPATH = lib/fraction
LIB = fraction

${EXEC}: ${EXEC}.o ${LIB}.o
	${COMPILE} -o ${EXEC} ${EXEC}.o ${LIB}.o

${EXEC}.o: ${EXEC}.cpp ${LIBPATH}.cpp ${LIBPATH}.h
	${COMPILE} -c ${EXEC}.cpp ${LIBPATH}.h

${LIB}.o: ${LIBPATH}.cpp ${LIBPATH}.h
	${COMPILE} -c ${LIBPATH}.cpp ${LIBPATH}.h