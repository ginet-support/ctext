all : src bin

src : splitit.c
	gcc -c splitit.c

bin : splitit.o
	gcc -o splitit splitit.o

distrib : Makefile splitit.c zoek.sh 

	tar cf splitit.src.tar Makefile splitit.c zoek.sh

clean :
	rm *.o splitit

install : splitit
	install -m 555 splitit /usr/local/bin

xyzzy : 
	echo Nothing Happens.

