CC = g++
CPPFLAGS = -g -O0 -std=c++17 -Wall
PROJ = .

start:
	mkdir -p bin
	@echo "Running program SumOfDigits.cpp:"
	make $(PROJ)/bin/SumOfDigits.o
	$(PROJ)/bin/SumOfDigits.o
	@echo
	@echo "Running program PrimeNumbers.cpp:"
	make $(PROJ)/bin/PrimeNumbers.o
	$(PROJ)/bin/PrimeNumbers.o
	@echo

$(PROJ)/bin/SumOfDigits.o: $(PROJ)/src/SumOfDigits.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ)/bin/SumOfDigits.o $(PROJ)/src/SumOfDigits.cpp

$(PROJ)/bin/PrimeNumbers.o: $(PROJ)/src/PrimeNumbers.cpp
	$(CC) $(CPPFLAGS) -o $(PROJ)/bin/PrimeNumbers.o $(PROJ)/src/PrimeNumbers.cpp