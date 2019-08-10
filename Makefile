CXX=g++
SDKROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk
CFLAGS=-std=c++11 -stdlib=libc++ -Ofast -Wno-deprecated -I/usr/local/include -I. -Icollision -isysroot $(SDKROOT)
LDFLAGS=-Wl,-search_paths_first -Wl,-headerpad_max_install_names -framework Cocoa
EXEC=main
SIZE=size -B -d

all: Polygon.o GJKCollisionDetector.o ExpandingSimplex.o Epsilon.o
	$(CXX) $(CFLAGS) $(LDFLAGS) main.cpp Polygon.o GJKCollisionDetector.o ExpandingSimplex.o Epsilon.o -o $(EXEC)
	$(SIZE) $(EXEC)

Polygon.o: collision/geometry/Polygon.cpp
	$(CXX) -c $(CFLAGS) collision/geometry/Polygon.cpp

GJKCollisionDetector.o: collision/algorithm/GJKCollisionDetector.cpp
	$(CXX) -c $(CFLAGS) collision/algorithm/GJKCollisionDetector.cpp

ExpandingSimplex.o: collision/algorithm/ExpandingSimplex.cpp
	$(CXX) -c $(CFLAGS) collision/algorithm/ExpandingSimplex.cpp

Epsilon.o: collision/math/Epsilon.cpp
	$(CXX) -c $(CFLAGS) collision/math/Epsilon.cpp

clean:
	rm -f $(EXEC) *.o *.gch collision/structures/*.gch
