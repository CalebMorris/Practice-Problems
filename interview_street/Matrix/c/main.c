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
int* neighbors( struct graph , int* , int );
int smallest( int* , int );

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

	for (i = 0; i < n-1; i++) {
		print_path(gr.paths[i]);
		printf("%d\n",is_connected(gr, gr.paths[i].node_a, gr.paths[i].node_b));
	}

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
	//TODO fix this function
	int i, u, v, alt;
	bool flag = false;
	int* Q = (int*)malloc(sizeof(int)*gr.size);
	int* dist = (int*)malloc(sizeof(int)*gr.size);
	int* tmpD = (int*)malloc(sizeof(int)*gr.size); 
	int* neigh;
	int q_size = gr.size;
	/*
	if( gr.adjacents[node_a][node_b] > 0 )
		return true;
	*/
	for (i = 0; i < gr.size; i++) {
		Q[i] = i;
		dist[i] = INT_MAX;
	}
	dist[node_a] = 0;
	while( q_size > 0 ) {
#ifdef DEBUG
		for (i = 0; i < gr.size; i++) {
			printf("Q[%d]: %d\n",i,Q[i]);
		}
		printf("q_size: %d\n",q_size);
		printf("dist:\n");
#endif
		for ( i = 0; i < gr.size; i++ ) {
			tmpD[i] = INT_MAX;
		}
		for (i = 0; i < gr.size; i++) {
			if( Q[i] >= 0 ) {
#ifdef DEBUG
				printf("i:%d\n",i);
#endif
				tmpD[i] = dist[i];
			}
		}
#ifdef DEBUG
		for (i = 0; i < gr.size; i++) {
			printf("dist[%d]: %d\n",i,dist[i]);
		}
		for (i = 0; i < gr.size; i++) {
			printf("tmpD[%d]: %d\n",i,tmpD[i]);
		}
#endif
		u = smallest(tmpD, gr.size); 
#ifdef DEBUG
		printf("u: %d\n",u);
#endif
		if( dist[u] == INT_MAX ) {
			break;
		}
		if( u == node_b ) {
			flag = true;
			return flag;
		}
		Q[u] = -1;
		--q_size;
		neigh = neighbors(gr, Q, u); 
#ifdef DEBUG
		for (i = 0; i < gr.size; i++) {
			printf("neigh[%d]: %d\n",i,neigh[i]);
		}
#endif
		for (i = 0; i < gr.size; i++) {
			if( neigh[i] >= 0 ) {
				v = neigh[i];
				alt = dist[u] + gr.adjacents[u][v];
				if( alt < dist[v] ) {
					dist[v] = alt;
				}
			}
		}
	}
	if( dist[node_b] < INT_MAX ) {
		flag = true;
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
	//TODO write this function
	printf("Searching\n");
}

int* neighbors( struct graph gr, int* q, int node ) {
	int* ret_val = (int*)malloc(sizeof(int)*gr.size);
	int i;
#ifdef DEBUG
		printf("\tnode: %d\n", node);
		for (i = 0; i < gr.size; i++) {
			printf("\tQ[%d]: %d\n",i,q[i]);
		}
#endif
	for (i = 0; i < gr.size; i++) {
		if( q[i] >= 0 && gr.adjacents[i][node] > 0 ) {
			ret_val[i] = i;
		}
		else {
			ret_val[i] = -1;
		}
	}
	return ret_val;
}

int smallest( int* z, int z_size ) {
	int small, i;
	if( z_size <= 0 )
		return -1;
	small = z[0];
	for (i = 1; i< z_size; i++) {
		if( z[i] < small ) {
			small = i;
		}
	}
	return small;
}
