CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS =

SRC = src/assistant.cpp src/gpt4all_interface.cpp src/speech_recognition.cpp src/speech_synthesis.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = build/assistant.exe  # Use .exe for Windows

all: build $(TARGET)

build:
	mkdir -p build

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(OBJ)
