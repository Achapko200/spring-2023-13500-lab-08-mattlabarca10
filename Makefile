main: main.o imageio.o invert.o invert-half.o box.o frame.o scale.o pixelate.o kernel.o 
	g++ -o main main.o imageio.o invert.o invert-half.o box.o frame.o scale.o pixelate.o kernel.o

main.o: main.cpp invert.h invert-half.h box.h frame.h scale.h pixelate.h kernel.h

imageio.o: imageio.cpp imageio.h

box.o: box.cpp imageio.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

clean:
	rm -f main main.o sample sample.o imageio.o invert.o invert-half.o box.o frame.o scale.o pixelate.o kernel.o
