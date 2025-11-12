#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1e4 + 15;
struct node{
	int u,v,val;
}e[maxn * 10];
int n,m,k,tot = 0,dot = 0;
int fa[maxn],c[15],city[maxn],cnt = 0;
long long ans = 0;
int dis[maxm][15];
int find(int a){
	return (fa[a] == a) ? a : fa[a] = find(fa[a]);
}
void merge(int a,int b){
	int x = find(a),y = find(b);
	fa[y] = x;
}
bool cmp(node a,node b){
	return a.val < b.val;
}
void kruskal(){
	for(int i = 1;i <= n;i++) fa[i] = i;
	sort(e + 1,e + n + 1,cmp);
	for(int i = 1;i <= n;i++){
		int u = e[i].u,v = e[i].v,w = e[i].val;
		if(find(u) == find(v)) continue;
		int trans = 0;
		for(int i = n + 1;i <= dot;i++){
			int val = c[i] + dis[u][i] + dis[v][i];
			if(city[i]) val -= c[i];
			city[i] = 1;
			if(val < w) w = val,trans = i;
		}
		ans += w;
		if(!trans) merge(u,v);
		else merge(u,trans),merge(v,trans);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	tot = m,dot = n;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].val);
		city[e[i].u] = 1,city[e[i].v] = 1;
	}
	for(int i = 1;i <= k;i++){
		int num;
		scanf("%d",&num);
		c[++dot] = num;
		city[dot] = 0;
		for(int j = 1;j <= n;j++){
			int w;
			scanf("%d",&w);
			dis[j][dot] = w;
		}
	}
	kruskal();
	printf("%lld",ans);
	return 0;
}