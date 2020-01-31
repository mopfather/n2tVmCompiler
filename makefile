VMTranslator: main.o tokenizer.o translator.o
	gcc -o VMTranslator main.o tokenizer.o translator.o
	
main.o: main.c tokenizer.h translator.h
	gcc -c main.c
	
translator.o: translator.c translator.h tokenizer.h
	gcc -c translator.c 
	
tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c
	
clean:
	rm *o