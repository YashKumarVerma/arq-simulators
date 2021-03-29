bin/build: bin/app.o  bin/rainbow.o bin/simulator.o
	g++ --std=c++17 bin/app.o bin/rainbow.o bin/simulator.o -o bin/build

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/simulator.o: includes/simulator/simulator.cpp includes/simulator/simulator.h
	g++ --std=c++17 -c includes/simulator/simulator.cpp -o bin/simulator.o

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

clean:
	rm -rf bin/*.o
