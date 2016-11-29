CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash
PROGRAMS=	src/dijkstras src/measure generate_map

all:		src/dijkstras src/measure

dijkstras:	src/dijkstras.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(PROGRAMS)
	
generate_map: generate_map.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test:		test-output test-memory test-time

test-output:	src/dijkstras
	@echo Testing output 0...
	@diff --suppress-common-lines -y <(./src/dijkstras < data/input0.txt) data/output0.txt
	@echo Testing output 1...
	@diff --suppress-common-lines -y <(./src/dijkstras < data/input1.txt) data/output1.txt
	@echo Testing output 2...
	@diff --suppress-common-lines -y <(./src/dijkstras < data/input2.txt) data/output2.txt
	@echo Testing output 3...
	@diff --suppress-common-lines -y <(./src/dijkstras < data/input3.txt | head -n 5) <(head -n 5 data/output3.txt)
	@diff --suppress-common-lines -y <(./src/dijkstras < data/input3.txt | tail -n 5) <(tail -n 5 data/output3.txt)

test-memory:	src/dijkstras
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./src/dijkstras < data/input1.txt 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-time:	$(PROGRAMS)
	@echo Testing time...
	@./src/measure ./src/dijkstras < data/input1.txt | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
