all: fork.c
	gcc fork.c
run: a.out
	./a.out
clean:
	rm -f *~ *.gch* a.out *.o *#*
