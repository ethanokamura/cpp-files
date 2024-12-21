CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -std=c++20

blackjack: main.o
	$(CPP) $(CPPFLAGS) main.o -o blackjack

main.o: main.cpp blackjackhand.h
	$(CPP) $(CPPFLAGS) -c main.cpp

blackjackhand.o: blackjackhand.cpp blackjackhand.h
	$(CPP) $(CPPFLAGS) -c blackjackhand.cpp

clean:
	rm -f blackjack *.o *~
