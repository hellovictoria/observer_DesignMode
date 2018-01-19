objects = main.o Subject.o ObserverDisplay.o

main:$(objects)
	g++ -o main $(objects)
main.o:main.cpp
	g++ -c main.cpp
Subject.o:Subject.cpp Subject.h
	g++ -c Subject.cpp
ObserverDisplay.o:ObserverDisplay.cpp ObserverDisplay.h
	g++ -c ObserverDisplay.cpp
clean:
	rm main $(objects) *.gch
