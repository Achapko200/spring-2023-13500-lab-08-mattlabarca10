main: imageio.o invert.o invert-half.o box.o frame.o scale.o pixelate.o kernel.o
	g++ -o main imageio.o invert.o invert-half.o box.o frame.o scale.o pixelate.o kernel.o

imageio.o: imageio.cpp imageio.h

invert.o: invert.cpp imageio.cpp

invert-half.o: invert-half.cpp imageio.cpp

box.o: box.cpp imageio.cpp

frame.o: frame.cpp imageio.cpp

scale.o: scale.cpp imageio.cpp

pixelate.o: pixelate.cpp imageio.cpp

kernel.o: kernel.cpp imageio.cpp

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

clean:
	rm -f main sample sample.o imageio.o invert.o invert-half.o box.o frame.o scale.o pixelate.o kernel.o
