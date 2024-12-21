CPP = g++
# -Ofast ?
CPPFLAGS = -Wall -Wextra -pedantic -std=c++17

# First target (default when running "make")
cs19s23as06: hatchet.o shall.o grand.o mean.o cool.o between.o grade.o god.o mad.o  seven.o
	$(CPP) $(CPPFLAGS) hatchet.o shall.o grand.o mean.o cool.o between.o grade.o god.o mad.o  seven.o -o cs19s23as06 -lncurses

# Builds the object file containing the main function
hatchet.o: hatchet.cpp star.h ha.h goodness.h sled.h
	$(CPP) $(CPPFLAGS) -c hatchet.cpp

# not sure uses ha.h sash.h goodness.h
shall.o: shall.cpp ha.h sash.h goodness.h
	$(CPP) $(CPPFLAGS) -c shall.cpp

# Grand constructs star.h
grand.o: grand.cpp guide.h star.h
	$(CPP) $(CPPFLAGS) -c grand.cpp

# Grand constructs likely.h and ha.h
mean.o: mean.cpp ha.h likely.h goodness.h
	$(CPP) $(CPPFLAGS) -c mean.cpp

# Cool constructs ha.h
cool.o: cool.cpp ha.h half.h goodness.h
	$(CPP) $(CPPFLAGS) -c cool.cpp

# Between constructs anywhere.h
between.o: between.cpp anywhere.h sash.h goodness.h
	$(CPP) $(CPPFLAGS) -c between.cpp

# Grade constructs goodness.h
grade.o: grade.cpp goodness.h
	$(CPP) $(CPPFLAGS) -c grade.cpp

# God constructs flash.h
god.o: god.cpp flash.h
	$(CPP) $(CPPFLAGS) -c god.cpp

# Mad constructs sash.h
mad.o: mad.cpp sash.h
	$(CPP) $(CPPFLAGS) -c mad.cpp

# Seven constructs stormy.h 
seven.o: seven.cpp stormy.h
	$(CPP) $(CPPFLAGS) -c seven.cpp

clean:
	rm -f ./*.o ./cs19s23as06