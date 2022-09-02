CMP = gcc -std=c11 -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
MAIN = my_dllist
EXEC = my_dllist

$(EXEC): $(MAIN).o
	$(CMP) $(MAIN).o -o $(EXEC)
	rm *.o

$(MAIN).o: $(MAIN).c
	$(CMP) -c $(MAIN).c -o $(MAIN).o

clean:
	rm $(EXEC)
