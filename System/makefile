main: */*.cpp */*/*.cpp */*/*/*.cpp */*.h */*/*.h */*/*/*.h main.cpp
	g++ */*.cpp */*/*.cpp */*/*/*.cpp main.cpp -o main -I .
	
run:
	./main

doc: */*.cpp */*/*.cpp */*/*/*.cpp */*.h */*/*.h */*/*/*.h main.cpp
	doxygen ../Report/Doxygen/Doxyfile