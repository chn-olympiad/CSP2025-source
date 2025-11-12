#include<bits/stdc++.h>
using namespace std;


const int N = 1e6 + 25, INF = 0x3f3f3f3f;
int head[N], to[2*N], nxt[2*N], c[2*N], vis[N], vil[30];
int I;
long long ret = 0;
int n, m, k;


void init() {
	I = 1;
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w) {
	to[I] = v;
	nxt[I] = head[u];
	head[u] = I;
	c[I] = w;
	I++;
}

void prim() {
	for (int i = 1; i <= k+n; i++) {
		long long tmp = INF;
		int id = -1;
		for (int j = head[i]; j != -1 && vis[j] == 0; j = nxt[j]) {
			if (i <= n) {
				if (c[j] < tmp) {
					tmp = 1LL * c[j];
					id = j;
				}
			} else {
				if (c[j] + vil[i-n] < tmp) {
					tmp = 1LL * (c[j] + vil[i-n]);
					vil[i-n] = 0;
					id = j;
				}
			} 
		}	
		vis[i] = 1;
		vis[id] = 1;
		ret += tmp;
		
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
	}
	for (int i = n+1; i <= k+n; i++) {
		scanf("%d", &vil[i-n]);
		for (int j = 1; j <= n; j++) {
			int w;
			scanf("%d", &w);
			addEdge(i, j, w);
		}
	}
	prim();
	printf("%lld\n", ret);
	return 0;
}
