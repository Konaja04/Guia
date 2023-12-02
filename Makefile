all: build

build:
	@echo "Compilando programa..."
	g++ -c p1.cpp -o ./bin/p1.o
	g++ -c p2.cpp -o ./bin/p2.o
	g++ -c p3.cpp -o ./bin/p3.o
	g++ -c p4.cpp -o ./bin/p4.o
	g++ -c p5.cpp -o ./bin/p5.o
	# g++ -c p6-8.cpp -o ./bin/p6-8.o
	g++ -c p7.cpp -o ./bin/p7.o
	g++ -c p9-10.cpp -o ./bin/p9-10.o
	g++ -c p11-12.cpp -o ./bin/p11-12.o
	g++  ./bin/p1.o ./bin/p2.o ./bin/p3.o ./bin/p4.o  ./bin/p5.o  ./bin/p7.o ./bin/p9-10.o ./bin/p11-12.o main.cpp -o ./bin/main
	@echo "Fin de la compilacion... Iniciando Ejecucion"
	# ./bin/main.exe <test.txt
	./bin/main.exe
clean:
	@echo "...Eliminando compilados..."
	-rm ./bin/*.exe 
	-rm ./bin/*.o