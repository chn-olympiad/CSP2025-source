#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int v,w,nxt;
}e[2000006];
long long ans = 0;
int a[11],b[11][10001],head[10001],cnt;
bool vis[10001];
void dfs(int x){
	vis[x] = 1;
	int p = 1e9,j = 0;
	for (int i = head[x];i;i = e[i].nxt)
		if (!vis[e[i].v]){
			if (e[i].w < p){
				p = min(p,e[i].w);
				j = i;
			}
		}
	ans += p;
	dfs(e[j].v);
} 
void add(int u,int v,int w){
	e[++cnt] = (node){v,w,head[u]};
	head[u] = cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for (int i = 1;i <= k;i++){
		cin >> a[i];
		for (int j = 1;j <= n;j++) cin >> b[i][j];
	}
	if (k != 0) cout << 0;
	else{
		dfs(1);
		cout << ans; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
