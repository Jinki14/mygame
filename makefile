CPP = g++
CPPFLAGS = -std=c++17 -Iinclude -Iexternal
SRC = $(wildcard src/*.cpp)
OUT = build/test

all:
	$(CPP) $(SRC) -o $(OUT) $(CPPFLAGS)

clean:
	del $(OUT)