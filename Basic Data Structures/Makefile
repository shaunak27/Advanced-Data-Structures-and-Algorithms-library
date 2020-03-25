all: stack
stack: s
	  ./stc
s: stack.o teststack.o
	 cc stack.o teststack.o -o stc
stack.o: stack.c 
		 cc -c stack.c
teststack.o: teststack.c
		     cc -c teststack.c
queue: q
	   ./que
q: queue.o testqueue.o
	cc queue.o testqueue.o -o que
queue.o: queue.c
		  cc -c queue.c
testqueue.o: testqueue.c
			 cc -c testqueue.c
list: l
	  ./lis
l: list.o listtest.o
	cc list.o listtest.o -o lis
list.o: list.c
		 cc -c list.c
listtest.o: listtest.c
			cc -c listtest.c
minpq: m
	   ./mpq
m: minpq.o testpq.o list.o
	cc minpq.o testpq.o list.o -o mpq
minpq.o: minpq.c
		cc -c minpq.c
testpq.o: testpq.c
		   cc -c testpq.c				  		     
clean: 
		rm *.o
