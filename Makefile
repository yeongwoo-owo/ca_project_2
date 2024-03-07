TARGET=mips-sim
CXX=g++
CXXFLAGS=-Wall
OBJECTS=mips-sim.o code.o word.o register.o cpu.o dataMemory.o

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
mips-sim.o: mips-sim.cpp
	$(CXX) $(CXXFLAGS) -c $^
code.o: code.cpp
	$(CXX) $(CXXFLAGS) -c $^
word.o: word.cpp
	$(CXX) $(CXXFLAGS) -c $^
register.o: register.cpp
	$(CXX) $(CXXFLAGS) -c $^
cpu.o: cpu.cpp
	$(CXX) $(CXXFLAGS) -c $^
dataMemory.o: dataMemory.cpp
	$(CXX) $(CXXFLAGS) -c $^
clean:
	rm $(OBJECTS) $(TARGET)