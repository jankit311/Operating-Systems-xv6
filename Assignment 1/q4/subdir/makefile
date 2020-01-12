objects = function1.o function2.o main.o
myob : $(objects)
	mkdir output
	$(CXX) -o myob $(objects)
	mv *.o output/
function1.o : function1.cpp
	$(CXX) -c function1.cpp
function2.o : function2.cpp
	$(CXX) -c function2.cpp
main.o : main.cpp functions.h
	$(CXX) -c main.cpp
clean : 
	rm -rf output
	rm -r myob
