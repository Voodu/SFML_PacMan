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

SFML: $(OBDIR)/main.o $(OBDIR)/Engine.o $(OBDIR)/GameObject.o $(OBDIR)/Scene.o $(OBDIR)/GameScene.o $(OBDIR)/PacMan.o $(OBDIR)/Transform.o $(OBDIR)/Dot.o $(OBDIR)/Wall.o $(OBDIR)/MovableObject.o $(OBDIR)/StaticObject.o $(OBDIR)/Ghost.o $(OBDIR)/Map.o $(OBDIR)/MenuScene.o $(OBDIR)/Fruit.o $(OBDIR)/Boost.o $(OBDIR)/Door.o $(OBDIR)/Spawn.o $(OBDIR)/Blinky.o $(OBDIR)/Pinky.o $(OBDIR)/Inky.o $(OBDIR)/Clyde.o $(OBDIR)/Text.o $(OBDIR)/ScoreText.o $(OBDIR)/LifesText.o $(OBDIR)/Menu.o
	$(CC) $^ -o $(APPNAME) $(CFLAGS) 

# $(OBDIR)/%.o: $(SRDIR)/%.cpp $(DEPS)
$(OBDIR)/%.o: $(SRDIR)/%.cpp $(INDIR)/%.hpp
	$(CC) -c $< -o $@ $(CFLAGS) 

.PHONY: clean

clean:
	-rm $(OBJ) $(APPNAME)
