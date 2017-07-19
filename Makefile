CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=
SOURCES=blackjack.cpp dealer.cpp card.cpp player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=blackjack

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
