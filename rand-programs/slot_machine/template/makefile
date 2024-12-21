CPP = g++
CPPFLAGS = -Wall -Wextra -pedantic -g

slots: main.o slot_machine.o
	$(CPP) $(CPPFLAGS) main.o slot_machine.o -o slots

main.o: main.cpp slot_machine.h
	$(CPP) $(CPPFLAGS) -c main.cpp

slot_machine.o: slot_machine.cpp slot_machine.h
	$(CPP) $(CPPFLAGS) -c slot_machine.cpp

clean:
	rm -f slots *.o *~ *.txt *.out
