CC = g++
CPPFLAGS = -g -O0 -std=c++17 -Wall
PROJ2_DIR = ./Ex2

lab2: $(PROJ2_DIR)/bin/task1_1.o $(PROJ2_DIR)/bin/task1_2.o $(PROJ2_DIR)/bin/task1_3.o
	@echo "Running program Ex1.5:"
	$(PROJ2_DIR)/bin/task1_1.o
	@echo
	@echo "Running program Ex1.11 (for loop):"
	$(PROJ2_DIR)/bin/task1_2.o
	@echo
	@echo "Running program Ex1.11 (while loop):"
	$(PROJ2_DIR)/bin/task1_2.o
	@echo

$(PROJ2_DIR)/bin/task1_1.o: $(PROJ2_DIR)/src/task1_1.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ2_DIR)/bin/task1_1.o $(PROJ2_DIR)/src/task1_1.cpp
$(PROJ2_DIR)/bin/task1_2.o: $(PROJ2_DIR)/src/task1_2.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ2_DIR)/bin/task1_2.o $(PROJ2_DIR)/src/task1_2.cpp
$(PROJ2_DIR)/bin/task1_3.o: $(PROJ2_DIR)/src/task1_3.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ2_DIR)/bin/task1_3.o $(PROJ2_DIR)/src/task1_3.cpp

clean:
	rm $(PROJ2_DIR)/bin/*.o
