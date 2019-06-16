CC = g++
EXECUTABLE = bin/main.exe
CFLAGS = -Wall -Werror -c -MD
SOURCES = $(wildcard $(addprefix src/,*.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.cpp),$(addprefix build/src/, %.o),$(wildcard $(addprefix src/, *.cpp)))
DEPENDENCIES = $(patsubst $(addprefix build/src/, %.o), $(addprefix build/src/, %.d), $(wildcard $(addprefix build/src/, *.o)))

TEST = bin/test.exe
TEST_DEPENDENCIES = build/test/main.o build/test/sort_price.o build/test/sort_relevance.o build/test/difference_gb.o build/test/difference_min.o build/test/difference_sms.o

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@ -std=c++11

build/src/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(DEPENDENCIES) $(TEST_DEPENDENCIES) $(TEST) bin/test.exe

.PHONY: test

test: $(TEST)
 
$(TEST): $(TEST_DEPENDENCIES)
	$(CC) -Wall -Werror $(TEST_DEPENDENCIES) -o $(TEST) -lm

build/test/main.o: test/main.cpp src/tarif.h	
	$(CC) -std=c++11 -I$(CATCH_SINGLE_INCLUDE) -Wall -Werror -c -I thirdparty -I src test/main.cpp -o build/test/main.o

build/test/sort_price.o: src/sort_price.cpp src/tarif.h	
	$(CC) -std=c++11 -I$(CATCH_SINGLE_INCLUDE) -Wall -Werror -c -I thirdparty -I src src/sort_price.cpp -o build/test/sort_price.o

build/test/sort_relevance.o: src/sort_relevance.cpp src/tarif.h	
	$(CC) -std=c++11 -I$(CATCH_SINGLE_INCLUDE) -Wall -Werror -c -I thirdparty -I src src/sort_relevance.cpp -o build/test/sort_relevance.o

build/test/difference_gb.o: src/difference_gb.cpp src/tarif.h 
	$(CC) -std=c++11 -I$(CATCH_SINGLE_INCLUDE) -Wall -Werror -c -I thirdparty -I src src/difference_gb.cpp -o build/test/difference_gb.o

build/test/difference_min.o: src/difference_min.cpp src/tarif.h 
	$(CC) -std=c++11 -I$(CATCH_SINGLE_INCLUDE) -Wall -Werror -c -I thirdparty -I src src/difference_min.cpp -o build/test/difference_min.o

build/test/difference_sms.o: src/difference_sms.cpp src/tarif.h 
	$(CC) -std=c++11 -I$(CATCH_SINGLE_INCLUDE) -Wall -Werror -c -I thirdparty -I src src/difference_sms.cpp -o build/test/difference_sms.o

