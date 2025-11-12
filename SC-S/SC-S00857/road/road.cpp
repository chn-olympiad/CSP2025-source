#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e6 + 8;
const int maxn = 1e4 + 8;
struct net{
	int to, nxt, w;
}e[maxm];
int n, m, k;
int head[maxn];
void add(int u, int v, int w){
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
	e[tot].w = w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1;i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1;i <= k; i++){
		int c; scanf("%d", &c);
		for(int i = 1;i <= n; i++){
			int w; scanf("%d", &w);
			if(c + w < e[i].w){
				add(++tot, i, c + w);
				add(i, ++tot, c + w);
			}
		}
	}
	return 0;
}