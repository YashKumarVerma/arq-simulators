all: bin/receiver bin/sender
	make bin/receiver bin/sender

bin/receiver: bin/receiver.o  bin/rainbow.o bin/simulator.o
	g++ --std=c++17 bin/receiver.o bin/rainbow.o bin/simulator.o -o bin/receiver

bin/sender: bin/sender.o  bin/rainbow.o bin/simulator.o
	g++ --std=c++17 bin/sender.o bin/rainbow.o bin/simulator.o -o bin/sender


# compiling sub-services
bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/simulator.o: includes/simulator/simulator.cpp includes/simulator/simulator.h
	g++ --std=c++17 -c includes/simulator/simulator.cpp -o bin/simulator.o


# final binary build mappings
bin/sender.o: source/sender.cpp
	g++ --std=c++17 -c source/sender.cpp -o bin/sender.o

bin/receiver.o: source/receiver.cpp
	g++ --std=c++17 -c source/receiver.cpp -o bin/receiver.o


# utility function
clean:
	rm -rf bin/*.o
