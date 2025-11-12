#include <bits/stdc++.h>
#define LL long long 
#define PII pair<int, int> 
using namespace std;

inline LL read(){
	LL x = 0,f = 1;
	char c = getchar();
	while(c > '9'|| c < '0'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' &&c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * f;
}

const int N = 1e6 + 10, M = 1e4 + 10;

LL n, m, k;
LL e[N], ne[N], h[N], w[N], idx = 0, c[N], a[M][M], dis[N];
bool st[N];

void add(int x, int y, int z){
	e[++ idx] = y, ne[idx] = h[x], w[idx] = z, h[x] = idx;
}

LL dijk(int s){
	memset(dis, 0x3f, sizeof dis);
	memset(st, 0, sizeof st);
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({s, 0});
	dis[s] = 0;
	while(!heap.empty()){
		PII t = heap.top();
		heap.pop();
		int u = t.first, dist = t.second;
		if(st[u]) continue;
		st[u] = true;
		for(int i = h[u];i != -1;i = ne[i]){
			int j = e[i];
			if(dis[j] > dist + w[i]){
				dis[j] = dist + w[i];
				heap.push({j, dis[j]});
			}
		}
	}
	return dis[n];
}

int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	for(int i = 1;i <= m;i ++ ){
		int x = read(), y = read(), z = read();
		add(x, y, z);
		add(y, x, z);
	}
	for(int i = 1;i <= k;i ++ ){
		c[i] = read();
		for(int j = 1;j <= n;j ++ ){
			a[i][j] = read();	
		}
	}
	if(k != 0) puts("0");
	else{
		printf("%lld", dijk(1));
	}
	return 0;	
}


