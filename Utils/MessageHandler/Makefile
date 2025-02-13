all: test

test: Example/test.cpp
	g++ -o test Example/test.cpp Src/MessageHandler.cpp Inc/MessageHandler.h -I. -pthread -g

clean:
	rm -f test