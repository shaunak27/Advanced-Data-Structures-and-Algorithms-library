#include<stdio.h>
#include "graph.h"
#include "qlist.h"
int main()
{
	graph g;
	int N, E, i, src, dest, weight, j;
	FILE *fp = fopen("testdata.txt","r");
	for(j = 0; j < 6; j++)
	{
		switch(j)
		{
		case 0:
		printf("\n\nBreadth First Search\n\n");
		fscanf(fp, "%d%d", &N, &E);
		init(&g, N);
		for(i = 0; i < E; i++)
		{
			fscanf(fp,"%d%d%d",&src, &dest, &weight);
			addedge(&g, src, dest, weight);
		}
		printgraph(&g);
		getbfs(&g, 0);
		break;
		case 1:
		printf("\n\nDepth First Search\n\n");
		fscanf(fp, "%d%d", &N, &E);
		init(&g, N);
		for(i = 0; i < E; i++)
		{
			fscanf(fp, "%d%d%d",&src, &dest, &weight);
			addedge(&g, src, dest, weight);
		}
		printgraph(&g);
		getdfs(&g, 0);
		break;
		case 2:
		printf("\n\nDjikstra's Shortest Path\n\n");
		fscanf(fp,"%d%d", &N, &E);
		init(&g, N);
		for(i = 0; i < E; i++)
		{
			fscanf(fp,"%d%d%d",&src, &dest, &weight);
			addedge(&g, src, dest, weight);
		}
		printgraph(&g);
		dijkstra(&g, 0);
		break;
		case 3:
		printf("\n\nBellman Ford Shortest Path\n\n");
		fscanf(fp,"%d%d", &N, &E);
		init(&g, N);
		for(i = 0; i < E; i++)
		{
			fscanf(fp,"%d%d%d",&src, &dest, &weight);
			addedge(&g, src, dest, weight);
		}
		printgraph(&g);
		bellman(&g, 0);
		break;
		case 4:
		printf("\n\nFloyd Warshall All Pair Shortest Paths\n\n");
		fscanf(fp,"%d%d", &N, &E);
		init(&g, N);
		for(i = 0; i < E; i++)
		{
			fscanf(fp,"%d%d%d",&src, &dest, &weight);
			addedge(&g, src, dest, weight);
		}
		printgraph(&g);
		floydwarshall(&g);
		break;
		case 5:
		printf("\n\nFord Fulkerson Maximum Flow\n\n");
		fscanf(fp,"%d%d", &N, &E);
		init(&g, N);
		for(i = 0; i < E; i++)
		{
			fscanf(fp,"%d%d%d",&src, &dest, &weight);
			addedge(&g, src, dest, weight);
		}
		printgraph(&g);
		printf("Maximum Flow is : %d\n",fordfulkerson(&g,0,N - 1));
		break;
		}
	}
	fclose(fp);
			
}
	
