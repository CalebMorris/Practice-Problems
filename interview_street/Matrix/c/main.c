#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct path {
	int node_a;
	int node_b;
	int weight;
} path;

struct graph {
	int size;
	struct path* paths;
	int** adjacents;
} graph;

void print_path( struct path );
void print_graph( struct graph );
bool is_connected( struct graph , int , int );
bool is_cut_off( struct graph, int* , int );
int search( struct graph , int* , int , int , int );

int main() {
	int n, k, i, j, machine;
	int* machines;
	struct path test; 
	struct graph gr;
	
	scanf("%d %d\n",&n,&k);
	printf("n: %d;k: %d\n",n,k);
	
	machines = (int*)malloc(sizeof(int)*k);

	gr.size = n;
	gr.paths = (struct path*)malloc(sizeof(struct path)*(gr.size-1));
	gr.adjacents = (int**)malloc(sizeof(int*)*gr.size);
	for (i = 0; i < gr.size; ++i) {
		gr.adjacents[i] = (int*)malloc(sizeof(int)*gr.size);
	}
	for (i = 0; i < gr.size; i++) {
		for (j = 0; j < gr.size; j++) {
			gr.adjacents[i][j] = -1;
		}
	}

	for (i = 0; i < n-1; ++i) {
		scanf("%d %d %d\n",&test.node_a,&test.node_b,&test.weight);
		gr.paths[i] = test;
		gr.adjacents[test.node_a][test.node_b] = test.weight;
		gr.adjacents[test.node_b][test.node_a] = test.weight;
	}
	for (i = 0; i < k; ++i) {
		scanf("%d\n",&machine);
		printf("%d\n",machine);
		machines[i] = machine;
	}
	/* Input done */
	print_graph(gr);

	search(gr, machines, k, 0, INT_MAX);

	return 0;
}

void print_path( struct path p ) {
	printf("Path: %d -> %d : %d \n",p.node_a,p.node_b,p.weight);
}

void print_graph( struct graph g ) {
	int i, j;
	printf("The graph is of size: %d\n",g.size);
	for (i = 0; i < g.size-1; i++) {
		print_path(g.paths[i]);
	}
	for (i = 0; i < g.size; i++) {
		for (j = 0; j < g.size; j++) {
			printf("%d ", g.adjacents[i][j]);
		}
		printf("\n");
	}
}

bool is_connected( struct graph gr, int node_a, int node_b ) {
	int i;
	bool flag = false;
	int* Q = (int*)malloc(sizeof(int)*gr.size);
	int* dist = (int*)malloc(sizeof(int)*gr.size);
	int* tmpD; 
	int q_size = gr.size;
	for (i = 0; i < gr.size; i++) {
		Q[i] = i;
		dist[i] = INT_MAX;
	}
	dist[node_a] = 0;
	while( q_size > 0 ) {
		tmpD = (int*)malloc(sizeof(int)*gr.size);
		for ( i = 0; i < gr.size; i++ ) {
			tmpD[i] = -1;
		}
		for (i = 0; i < gr.size; i++) {
			if( Q[i] > 0 ) {
				tmpD[i] = i;
			}
		}
	}

	return flag;
}

bool is_cut_off( struct graph gr, int* machines, int machine_size ) {
	int i, j;
	for (i = 0; i < machine_size; i++) {
		for (j = 0; j < machine_size; j++) {
			if( i > j ) {
				if( is_connected(gr, machines[i], machines[j]) )
					return false;
			}
		}
	}
	return true;
}

int search( struct graph gr, int* machines, int machine_size, int alt, int cheap ) {
	printf("Searching\n");
}

int* neighbors( struct graph gr, int node ) {
}
