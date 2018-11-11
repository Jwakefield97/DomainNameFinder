all: listIPDNS

listIPDNS: listIPDNS.c
	gcc -Wall -g -o listIPDNS listIPDNS.c 

clean: 
	rm -f listIPDNS
	rm -f jsw5227.tgz

fresh: clean all

run: 
	./listIPDNS 255.255.0.0 216.58.192.142

pack: clean
	mkdir jsw5227
	cp listIPDNS.c jsw5227/listIPDNS.c
	cp Makefile jsw5227/Makefile
	cp Readme.md jsw5227/Readme.md
	tar cvfz jsw5227.tgz jsw5227
	rm -rf jsw5227
	



