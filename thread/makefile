# Variables
CXX = g++
CXXFLAGS = -I/usr/include/opencv4
LDFLAGS = -lopencv_core -lopencv_highgui -lopencv_imgcodecs -pthread

# Target principal
grayscale: main.o
    $(CXX) main.o -o grayscale $(LDLIBS)

# Compilar main.cpp -> main.o
main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

# Limpiar
clean:
    rm -f grayscale main.o