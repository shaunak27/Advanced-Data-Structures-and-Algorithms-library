#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph.h"
#include "qlist.h"
#include "minpq.h"
#include<limits.h>
#define INF INT_MAX/5

/* initialize the graph   */

void init(graph *g, int v)
{
	int i, j;
	g->V = v;
	g->adj = (int**)malloc(sizeof(int*) * v);
	for(i = 0; i < v; i++)
	{
		g->adj[i] = (int*)malloc(sizeof(int) * v);
	}
	g->weight = (int**)malloc(sizeof(int*) * v);
	for(i = 0; i < v; i++)
	{
		g->weight[i] = (int*)malloc(sizeof(int) * v);
	}
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			g->adj[i][j] = 0;
			g->weight[i][j] = INT_MAX/3;
			if(i == j)
			{
				g->weight[i][j] = 0;
			}
		}
	}		
	g->visited = (int*)malloc(sizeof(int) * v);
	for(j = 0; j < v; j++)
		{
			g->visited[j] = 0;
		}	
	g->parent = (int*)malloc(sizeof(int) * v);
	for(j = 0; j < v; j++)
		{
			g->parent[j] = -1;
		}		
}

/* adds and edge of given weight between the two input vertices  */

void addedge(graph *g, int src, int dest, int weight)
{
	if(src < g->V && dest < g->V)
	{
		g->adj[src][dest] = 1;
		g->weight[src][dest] = weight;
		if(src = dest)
		{
			g->weight[src][dest] = 0;
		}
	}
	
}

/* removes edge between given vertices  */

void remedge(graph *g, int src, int dest)
{
	if(src < g->V && dest < g->V)
	{
		g->adj[src][dest] = 0;
	}
}

/* prints the graph */

void printgraph(graph *g)
{
	int i, j;
	printf("Original Graph\n");
	printf("SOURCE\tWEIGHT\tDESTINATION\n");
	for(i = 0; i < g->V; i++)
	{
		for(j = 0; j < g->V; j++)
		{
			if(g->adj[i][j] > 0)
			{
				printf("%d\t%d\t%d\n", i, g->adj[i][j], j);
			}
		}
	}
	printf("\n\n");
}

/*Breadth First Search of the graph */

void bfs(graph *g, int src, int flag)
{
	queue q;
	int j;
	qinit(&q);
	enq(&q,src);
	for(j = 0; j < g->V; j++)
		{
			g->visited[j] = 0;
		}		
	g->visited[src] = 1;
	while(!isempty(&q))
	{
		int t = deq(&q);
		if(flag == 0)
		{
		printf("%d ",t);
		}
		for(j = 0; j < g->V; j++)
		{
			if(g->adj[t][j] == 1)
			{
				if(g->weight[t][j] != 0)
				{
					if(!g->visited[j])
					{
						g->parent[j] = t;
						g->visited[j] = 1;
						enq(&q, j);
					}
				}
			}
		}
	}
}
	
void getbfs(graph *g, int src)
{
	int i, c = 0;
	for(i = src; c < g->V; i = (i + 1)%(g->V))
	{
		if(g->visited[i] == 0)
		{
			bfs(g, i, 0);
		}
		c++;
	}
}

/* Depth First Search of the Graph  */

void dfs(graph *g, int src)
{
	int j;
	g->visited[src] = 1;
	printf("%d ",src + 1);
	for(j = 0; j < g->V; j++)
		{
			if(g->adj[src][j] == 1)
			{
				if(!g->visited[j])
				{
					g->visited[j] = 1;
					dfs(g, j);
				}
			}
		}
}	
void getdfs(graph *g, int src)
{
	int i, c = 0;
	for(i = src; c < g->V; i = (i + 1)%(g->V))
	{
			if(g->visited[i] == 0)
		{
			dfs(g, i);
		}
		c++;
	}
}

/* Single Source Shortest Paths using Djikstra's Algorithm  */

void dijkstra(graph *g, int src)
{
	int *dist, i, j;
	priority_queue p;
	pqinit(&p);
	dist = (int*)malloc((g->V) * sizeof(int));
	for(i = 0; i < g->V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	pqenq(&p, src);
	while(!pqempty(&p))
	{
		int t = pqdeq(&p);
		g->visited[t] = 1;
		for(j = 0;j < g->V; j++)
		{
			if(g->adj[t][j] == 1)
			{
				if(g->visited[j] == 0 && dist[j] > dist[t] + g->weight[t][j])
				{
					dist[j] = dist[t] + g->weight[t][j];
					pqenq(&p,j);
				}
			}
		}
		
	}
	printf("VERTEX\tDISTANCE FROM SOURCE\n");
	for(i = 0;i < g->V; i++)
	{
		printf("%d\t%d\n",i,dist[i]);
	}	
}

/* Single Source Shortest Paths for graph with negative edges using Bellman Ford Algorithm */

void bellman(graph *g, int src)
{
	int *dist, i, j, k;
	dist = (int*)malloc((g->V) * sizeof(int));
	for(i = 0; i < g->V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	for(i = 0; i < g->V - 1; i++)
	{
		for(j = 0; j < g->V; j++)
		{
			for(k = 0; k < g->V; k++)
			{
				if(dist[k] > dist[j] + g->weight[j][k])
				{
					dist[k] = dist[j] + g->weight[j][k];
				}
			}
		}
	}
	for(j = 0; j < g->V; j++)
	{
		for(k = 0; k < g->V; k++)
		{
			if(dist[k] > dist[j] + g->weight[j][k])
			{
				printf("Negative Cycle Detected\n");
				exit(1);
			}
		}
	}
	printf("VERTEX\tDISTANCE\n");
	for(i = 0;i < g->V; i++)
	{
		printf("%d\t%d\n", i, dist[i]);
	}
}

/* All source Shortest Path by Floyd Warshall  */

void floydwarshall(graph *g)
{
	int i, j, k;
	for (k = 0; k < g->V; k++)
        {
                for (i = 0; i< g->V; i++)
                {
                        for (j = 0; j < g->V; j++)
                        {
                                if (g->weight[i][j] > g->weight[i][k] + g->weight[k][j])
                                {
                                        if (g->weight[i][k] <= INF && g->weight[k][j] <= INF)
                                        {
                                                g->weight[i][j] = g->weight[i][k] + g->weight[k][j];
                                        }
                                }
                        }
                }
   		}
   	for (i = 0; i < g->V; i++)
        {
				printf("Source\tWeight\tDestination\n");
                for (j = 0; j < g->V; j++)
                {
                        if(g->weight[i][j]<=INF)
                        printf("%d\t%d\t%d\n", i, g->weight[i][j], j);
                }
        }

}

/* Maximum Flow in a network given the source sink and capacities of edges by
	Ford Fulkerson Algorithm  */

int fordfulkerson(graph *g, int s, int t)
{
	int u, v, i, j;
	graph rg;
	init(&rg, g->V);
	rg = *g;
	for(i = 0; i < g->V; i++)
	{
		for(j = 0; j < g->V; j++)
		{
			if(rg.weight[i][j] >= INT_MAX / 8)
			rg.weight[i][j] = 0;
		}
	}
	int maxflow = 0;
	bfs(&rg, s, 1);
	while(rg.visited[t] == 1)
	{
		int pathflow = INT_MAX;
		for(v = t; v != s; v = rg.parent[v])
		{
			u = rg.parent[v];
			pathflow = pathflow < rg.weight[u][v] ? pathflow : rg.weight[u][v];
		}
		for (v = t; v != s; v=rg.parent[v]) 
        { 
            u = rg.parent[v]; 
            rg.weight[u][v] -= pathflow; 
            rg.weight[v][u] += pathflow; 
        } 
        maxflow += pathflow;
        bfs(&rg, s, 1);
    }
    return maxflow;    
 }
		
	
