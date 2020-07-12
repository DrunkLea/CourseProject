# Shuyao Li
# 915277384

CXXFLAGS=-Wall

all:	calculator useFraction

calculator: calculator.o
	$(CXX) $(CF) -o $@ $^

useFraction: useFraction.cpp
	$(CXX) $(CF) -o $@ $^

clean:
	rm -f calculator useFraction *.o
