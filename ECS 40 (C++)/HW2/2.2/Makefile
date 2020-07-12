# Shuyao Li
# 915277384

CXXFLAGS=-Wall

all:  maintenance testAircraft

maintenance: Aircraft.cpp maintenance.cpp
	$(CXX) $(CF) -o $@ $^

testAircraft: Aircraft.cpp testAircraft.cpp
	$(CXX) $(CF) -o $@ $^

clean:
		rm -f maintenance testAircraft *.o
