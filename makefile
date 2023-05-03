run: ws
	./build/ws

ws: main.c build/lexer.o build/token.o build/common.o build/ast.o build/parser.o
	gcc -o build/ws main.c build/token.o build/lexer.o build/common.o build/ast.o build/parser.o

build/lexer.o: src/lexer.c src/includes/lexer.h
	gcc -o build/lexer.o -c src/lexer.c

build/parser.o: src/parser.c src/includes/parser.h
	gcc -o build/parser.o -c src/parser.c

build/token.o: src/token.c src/includes/token.h
	gcc -o build/token.o -c src/token.c

build/common.o: src/common.c src/includes/common.h
	gcc -o build/common.o -c src/common.c

build/ast.o: src/ast.c src/includes/ast.h
	gcc -o build/ast.o -c src/ast.c

clean:
	rm build/*