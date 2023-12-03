# Definición de variables
CXX = g++
CXXFLAGS = -I/usr/include/opencv4 
LDFLAGS = -lopencv_core -lopencv_highgui -lopencv_imgcodecs

# Regla principal: construye el ejecutable
secuencial: main.o 
    $(CXX) main.o -o secuencial $(LDFLAGS)

# Regla para compilar main.cpp -> main.o
main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

# Regla para limpiar
clean:
    rm -f secuencial main.o