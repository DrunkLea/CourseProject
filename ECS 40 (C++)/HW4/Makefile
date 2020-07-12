#Shuyao Li
#915277384
CXXFLAGS=-Wall
all: testCode testRunway testFacility testSiteNumber

testFacility: testFacility.cpp Facility.cpp gcdistance.cpp
	$(CXX) $(CF) -o $@ $^
testRunway: testRunway.cpp Runway.cpp
	$(CXX) $(CF) -o $@ $^
testCode: testCode.cpp Facility.cpp Runway.cpp gcdistance.cpp
	$(CXX) $(CF) -o $@ $^
testSiteNumber: testSiteNumber.cpp Facility.cpp Runway.cpp gcdistance.cpp
	$(CXX) $(CF) -o $@ $^
clean:
		rm -f testCode testRunway testFacility testSiteNumber
