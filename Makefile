


CC=gcc
CFLAGS=-Wall -g

OBJ=y.tab.o lex.yy.o main.o

all: compilateur

compilateur: lex.yy.c y.tab.c asm_ins.c tableau.c crosscompiler.c 
	$(CC) $(CFLAGS) lex.yy.c y.tab.c tableau.c asm_ins.c crosscompiler.c -o compilateur

y.tab.c : compilateur.y
	yacc -d -t -v compilateur.y

lex.yy.c: compilateur.l
	lex compilateur.l

clean:
	rm -rf compilateur lex.yy.c y.tab.c

test: compilateur
	./compilateur < sample1.c


