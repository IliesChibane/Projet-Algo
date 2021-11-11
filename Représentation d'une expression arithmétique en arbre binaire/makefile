CC = g++
OBJS = main.o lex.o sem.o
FLAGS = -g
PROG = prog

$(PROG) : $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)

main.o : main.cpp lex.hpp sem.hpp tree.hpp
	$(CC) $(FLAGS) -o main.o -c main.cpp

lex.o : lex.cpp lex.hpp
	$(CC) $(FLAGS) -o lex.o -c lex.cpp

sem.o : sem.cpp sem.hpp lex.hpp tree.hpp
	$(CC) $(FLAGS) -o sem.o -c sem.cpp

clean :
	rm -f $(PROG) $(OBJS)
