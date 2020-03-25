all: graph
graph: g
		./grp
g: graph.o testgraph.o minpq.o list.o qlist.o
		cc graph.o testgraph.o minpq.o list.o qlist.o -o grp
graph.o: graph.c
		cc -c graph.c
testgraph.o: testgraph.c
		cc -c testgraph.c
minpq.o: minpq.c
		cc -c minpq.c
qlist.o: qlist.c
		cc -c qlist.c
list.o: list.c
		cc -c list.c
clean:
		rm *.o
