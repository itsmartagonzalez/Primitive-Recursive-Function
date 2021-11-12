OBJECTS = Main.o BasicPRFs.o
CFLAGS = -g -c -O3 -std=c++17 -I../include

exe: $(OBJECTS)
	g++  $(OBJECTS) -o ../bin/exe
	mv *.o ../obj

Main.o:
	g++ $(CFLAGS) ../src/Main.cc

BasicPRFs.o:
	g++ $(CFLAGS) ../src/BasicPRFs.cc

.PHONY: clean

clean:
	rm -rf ../obj/*.o
	rm -rf ../build/*.o
	rm -rf ../bin/*

run:
	make -s clean && make -s && ../bin/exe