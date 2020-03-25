all: bst
bst: b
	./bina
b: bst.o bsttest.o
	  cc bst.o bsttest.o -o bina
bst.o: bst.c
	   cc -c bst.c
bsttest.o: bsttest.c
		cc -c bsttest.c
avl: a
	./avlt
a: AVL.o testavl.o
	cc AVL.o testavl.o -o avlt
AVL.o: AVL.c
	cc -c AVL.c
testavl.o: testavl.c
	cc -c testavl.c
trie: t
	./tri
t: trie.o testtrie.o 
	cc trie.o testtrie.o -o tri
trie.o: trie.c
		cc -c trie.c
testtrie.o: testtrie.c
		cc -c testtrie.c
btree: bt
		./btr
bt:	btree.o testbtree.o
	cc btree.o testbtree.o -o btr
btree.o: btree.c
	cc -c btree.c
testbtree.o: testbtree.c
	cc -c testbtree.c
rbt: r
	 ./red
r: rbt.o rbttest.o
	cc rbt.o rbttest.o -o red
rbt.o: rbt.c
	cc -c rbt.c
rbttest.o: rbttest.c
	cc -c rbttest.c
clean:
		rm *.o
