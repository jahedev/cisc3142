CC = g++
CPPFLAGS = -g -O0 -std=c++17 -Wall
PROJ2_DIR = ./Ex2
PROJ4_DIR = ./Ex4

lab4: $(PROJ4_DIR)/bin/Ex317.o $(PROJ4_DIR)/bin/Ex323.o $(PROJ4_DIR)/bin/Ex428.o
	@echo "Running program Ex 3.17:"
	$(PROJ4_DIR)/bin/Ex317.o
	@echo
	@echo "Running program Ex 3.23:"
	$(PROJ4_DIR)/bin/Ex323.o
	@echo
	@echo "Running program Ex 4.28:"
	$(PROJ4_DIR)/bin/Ex428.o
	@echo

$(PROJ4_DIR)/bin/Ex317.o: $(PROJ4_DIR)/src/Ex317.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Ex317.o $(PROJ4_DIR)/src/Ex317.cpp

$(PROJ4_DIR)/bin/Ex323.o: $(PROJ4_DIR)/src/Ex323.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Ex323.o $(PROJ4_DIR)/src/Ex323.cpp

$(PROJ4_DIR)/bin/Ex428.o: $(PROJ4_DIR)/src/Ex428.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Ex428.o $(PROJ4_DIR)/src/Ex428.cpp

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
