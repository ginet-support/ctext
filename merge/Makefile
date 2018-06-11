all : src bin

src : merge.c
	gcc -c merge.c

bin : merge.o
	gcc -o merge merge.o

distrib : Makefile merge.c 

	tar cf merge.src.tar Makefile merge.c

clean :
	rm *.o merge

install : merge
	install -m 555 merge /usr/local/bin

xyzzy : 
	echo Nothing Happens.

