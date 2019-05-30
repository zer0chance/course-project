CC = g++
EXECUTABLE = bin/main.exe
CFLAGS = -Wall -Werror -c -MD
SOURCES = $(wildcard $(addprefix src/,*.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.cpp),$(addprefix build/src/, %.o),$(wildcard $(addprefix src/, *.cpp)))
DEPENDENCIES = $(patsubst $(addprefix build/src/, %.o), $(addprefix build/src/, %.d), $(wildcard $(addprefix build/src/, *.o)))

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@ -std=c++11

build/src/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

.PHONY : clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(DEPENDENCIES) bin/test.exe
