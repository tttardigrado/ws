run: ws
	./build/ws

ws: main.c build/lexer.o build/token.o
	gcc -o build/ws main.c build/token.o build/lexer.o

build/lexer.o: src/lexer.c src/includes/lexer.h
	gcc -o build/lexer.o -c src/lexer.c

build/token.o: src/token.c src/includes/token.h
	gcc -o build/token.o -c src/token.c

clean:
	rm build/*