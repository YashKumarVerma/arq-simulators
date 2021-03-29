ENVIRONMENT_DIR=./environment

# to run the simulation in one line
simulate: bin/receiver bin/sender
	#
	#
	# removing old builds
	#
	#
	rm -rf bin/*

	#
	#
	# building packages
	#
	#
	make all

	#
	#
	# take artifacts into environment
	#
	#
	cp bin/sender environment/client_sender
	cp bin/receiver environment/client_receiver
	cp seed.py environment/seed.py

	#
	#
	# Enter environment
	# python3 seed.py
	# ./client_sender
	#
	#

all: bin/receiver bin/sender
	make bin/receiver bin/sender

bin/receiver: bin/receiver.o  bin/rainbow.o bin/simulator.o bin/log.o
	g++ --std=c++17 bin/receiver.o bin/rainbow.o bin/simulator.o bin/log.o -o bin/receiver

bin/sender: bin/sender.o  bin/rainbow.o bin/simulator.o bin/log.o
	g++ --std=c++17 bin/sender.o bin/rainbow.o bin/simulator.o bin/log.o -o bin/sender


# compiling sub-services
bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/simulator.o: includes/simulator/simulator.cpp includes/simulator/simulator.h
	g++ --std=c++17 -c includes/simulator/simulator.cpp -o bin/simulator.o

bin/log.o : includes/log/log.h
	g++ --std=c++17 -c includes/log/log.cpp -o bin/log.o


# final binary build mappings
bin/sender.o: source/sender.cpp
	g++ --std=c++17 -c source/sender.cpp -o bin/sender.o

bin/receiver.o: source/receiver.cpp
	g++ --std=c++17 -c source/receiver.cpp -o bin/receiver.o


# utility function
clean:
	rm -rf bin/*.o
