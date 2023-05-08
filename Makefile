main: main.o imageio.o box.o 
	g++ -o main main.o imageio.o box.o

main.o: main.cpp box.h 

imageio.o: imageio.cpp imageio.h

box.o: box.cpp imageio.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

clean:
	rm -f main main.o sample sample.o imageio.o box.o
