# Definición de variables
CXX = g++
CXXFLAGS = -I/usr/include/opencv4
LDFLAGS = -lopencv_core -lopencv_highgui -lopencv_imgcodecs

# Regla principal: construye el ejecutable
openmp: main.o
    $(CXX) main.o -o openmp $(LDFLAGS)

# Regla para compilar main.cpp -> main.o
main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

# Regla para limpiar
clean:
    rm -f openmp main.o
