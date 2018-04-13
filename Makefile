
CPPFLAGS  += -std=c++11

myProg: MyClass1.o MyClass2.o myMain.o 
	g++ $(CPPFLAGS) MyClass1.o MyClass2.o myMain.o -o ./myProg

MyClass1.o: MyClass1.cpp
	g++ $(CPPFLAGS) -c MyClass1.cpp
	
Matrix.o: MyClass2.cpp
	g++ $(CPPFLAGS) -c MyClass2.cpp
	
myMain.o: myMain.cpp
	g++ $(CPPFLAGS) -c myMain.cpp
		
clean:
	rm -f *.o *~	
