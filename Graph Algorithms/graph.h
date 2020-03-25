#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct graph
{
	int V;
	int** adj;
	int* visited;
	int **weight;
	int *parent;
}graph;
void init(graph *g, int v);
void addedge(graph *g, int src, int dest, int weight);
void remedge(graph *g, int src, int dest);
void printgraph(graph *g);
void getbfs(graph *g, int src);
void bfs(graph *g, int src, int);
void getdfs(graph *g, int src);
void dfs(graph *g, int src);
void dijkstra(graph *g, int src);
void bellman(graph *g, int src);
void floydwarshall(graph *g);
int fordfulkerson(graph *g, int, int);
