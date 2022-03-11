all: romanos.o testa_romanos.cpp
	g++ -std=c++11 -Wall  romanos.o testa_romanos.cpp -o testa_romanos
	

romanos.o : romanos.cpp romanos.hpp
	g++ -std=c++11 -Wall  -c romanos.cpp
	
	
	
	
	

clean:
	rm -rf *.o *.exe
	
	
