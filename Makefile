CC=g++ -g
CCFLAGS= -Wall -Werror -std=c++11
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cpp)
HDR= $(wildcard *.h)
OBJ= $(SRC:.cpp=.o)
EXEC= ParadisePaper


all: $(EXEC)

test.o: $(HDR)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@   $(LIBFLAGS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) 
