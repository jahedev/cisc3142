CC = g++
CPPFLAGS = -g -O0 -std=c++17 -Wall
PROJ1_DIR = ./Ex1
PROJ2_DIR = ./Ex2
PROJ3_DIR = ./Ex2
PROJ4_DIR = ./Ex4
PROJ5_DIR = ./Ex5
PROJ7_DIR = ./Ex7
# PROJ8_DIR = ./Ex8
PROJ9_DIR = ./Ex9


setup:
	mkdir -p $(PROJ1_DIR)/bin
	mkdir -p $(PROJ2_DIR)/bin
	mkdir -p $(PROJ3_DIR)/bin
	mkdir -p $(PROJ4_DIR)/bin
	mkdir -p $(PROJ7_DIR)/bin
	# mkdir -p $(PROJ8_DIR)/bin
	mkdir -p $(PROJ9_DIR)/bin

lab9: $(PROJ9_DIR)/bin/weather.o
	@echo "\nRunning program Weather Averages:\n"
	cd $(PROJ9_DIR) && ./bin/weather.o # set CD to PROJ9_DIR for weather.csv file
	@echo

$(PROJ9_DIR)/bin/weather.o: $(PROJ9_DIR)/src/weather.cpp $(PROJ9_DIR)/src/weather.h
	$(CC) $(CPPFLAGS) -o $(PROJ9_DIR)/bin/weather.o $(PROJ9_DIR)/src/weather.cpp


lab7: $(PROJ7_DIR)/bin/Pixel.o $(PROJ7_DIR)/bin/Q1_main.o $(PROJ7_DIR)/bin/Q2_main.o
	@echo "Running program Pixel:"
	$(PROJ7_DIR)/bin/Pixel.o
	@echo
	@echo "Running program Q1:"
	$(PROJ7_DIR)/bin/Q1_main.o
	@echo
	@echo "Running program Q2:"
	$(PROJ7_DIR)/bin/Q2_main.o
	@echo

$(PROJ7_DIR)/bin/Pixel.o: $(PROJ7_DIR)/src/Pixel.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ7_DIR)/bin/Pixel.o $(PROJ7_DIR)/src/Pixel.cpp

$(PROJ7_DIR)/bin/Q1_main.o: $(PROJ7_DIR)/src/Q1_main.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ7_DIR)/bin/Q1_main.o $(PROJ7_DIR)/src/Q1_main.cpp

$(PROJ7_DIR)/bin/Q2_main.o: $(PROJ7_DIR)/src/Q2_main.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ7_DIR)/bin/Q2_main.o $(PROJ7_DIR)/src/Q2_main.cpp


lab4: $(PROJ4_DIR)/bin/Ex317.o $(PROJ4_DIR)/bin/Ex323.o $(PROJ4_DIR)/bin/Ex428.o $(PROJ4_DIR)/bin/Inflation.o $(PROJ4_DIR)/bin/Nutrition.o
	@echo "Running program Ex 3.17:"
	$(PROJ4_DIR)/bin/Ex317.o
	@echo
	@echo "Running program Ex 3.23:"
	$(PROJ4_DIR)/bin/Ex323.o
	@echo
	@echo "Running program Ex 4.28:"
	$(PROJ4_DIR)/bin/Ex428.o
	@echo
	@echo "Running program Inflation:"
	$(PROJ4_DIR)/bin/Inflation.o
	@echo
	@echo "Running program Nutrition:"
	$(PROJ4_DIR)/bin/Nutrition.o
	@echo

$(PROJ4_DIR)/bin/Ex317.o: $(PROJ4_DIR)/src/Ex317.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Ex317.o $(PROJ4_DIR)/src/Ex317.cpp

$(PROJ4_DIR)/bin/Ex323.o: $(PROJ4_DIR)/src/Ex323.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Ex323.o $(PROJ4_DIR)/src/Ex323.cpp

$(PROJ4_DIR)/bin/Ex428.o: $(PROJ4_DIR)/src/Ex428.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Ex428.o $(PROJ4_DIR)/src/Ex428.cpp
	
$(PROJ4_DIR)/bin/Inflation.o: $(PROJ4_DIR)/src/Inflation.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Inflation.o $(PROJ4_DIR)/src/Inflation.cpp
	
$(PROJ4_DIR)/bin/Nutrition.o: $(PROJ4_DIR)/src/Nutrition.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ4_DIR)/bin/Nutrition.o $(PROJ4_DIR)/src/Nutrition.cpp

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
	find . -iname "bin" | xargs rm -rf
