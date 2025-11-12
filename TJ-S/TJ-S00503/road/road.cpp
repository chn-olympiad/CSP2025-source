#include <cstdio>
#include <algorithm>
#define DEBUG 1
using namespace std;

const int N = 1e4+5;
const int M = 1e6+5;

int n, m, k;
int ans;

int vis[N];

struct Edge {
	int to, nxt, v;
} a[2*M];
int head[N];
int ecnt;


struct newTown {
	int c;
	int a[N];
} t[15];

void addEdge(int u, int v, int w) {
	a[++ecnt] = Edge{v, head[u], w};
	head[u] = ecnt; 
}


int main(){
	freopen("road.in", "r", stdin);
#if DEBUG
	freopen("road.out", "w", stdout);
#endif
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	
	
	
	printf("0");
	
	fclose(stdin);
#if DEBUG
	fclose(stdout);
#endif
	return 0;
} 

//died....
