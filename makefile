APPNAME = PacMan.out
CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -g -std=c++17 -Wall -pedantic -Werror
INDIR = include
SRDIR = src
OBDIR = obj

DEPS = $(wildcard $(INDIR)/*.hpp)
SRCS = $(wildcard $(SRDIR)/*.cpp)
OBJ = $(wildcard $(OBDIR)/*.o)

all: SFML

SFML: $(OBDIR)/main.o $(OBDIR)/Engine.o $(OBDIR)/GameObject.o $(OBDIR)/Scene.o $(OBDIR)/GameScene.o $(OBDIR)/PacMan.o $(OBDIR)/Transform.o $(OBDIR)/Dot.o $(OBDIR)/Wall.o $(OBDIR)/MovableObject.o $(OBDIR)/Ghost.o $(OBDIR)/Map.o $(OBDIR)/MenuScene.o $(OBDIR)/Fruit.o $(OBDIR)/Boost.o $(OBDIR)/Door.o $(OBDIR)/Spawn.o
	$(CC) $^ -o $(APPNAME) $(CFLAGS) 

$(OBDIR)/%.o: $(SRDIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS) 

.PHONY: clean

clean:
	-rm $(OBJ) $(APPNAME)
