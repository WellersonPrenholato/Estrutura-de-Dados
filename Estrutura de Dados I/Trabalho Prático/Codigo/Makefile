all:main.o fila.o pilha.o permutar.o
	gcc -o exec *.o

fila.o: fila.c
	gcc -c fila.c

permutar.o: permutar.c
	gcc -c permutar.c

pilha.o: pilha.c
	gcc -c pilha.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o
