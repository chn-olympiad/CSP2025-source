#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int M = 1000006,N = 10004,K = 11;
struct Node{
	int x,y,z;
}edge[M+N*K];
int n,m,k,c[N+K],fa[N+K],vis[N+K],cnt;
ll ans;
bool cmp(Node x,Node y){
	return x.z < y.z;
}
int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void add_edge(int x,int y,int z){
	edge[++cnt] = {x,y,z};
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n+k;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
	}
	for(int i = n+1;i <= n+k;i++){
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++){
			int z;
			scanf("%d",&z);
			add_edge(i+k,j,z);
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	int cnt = 1;
	for(int i = 1;i <= m && cnt < n+k;i++){
		int fx = find(edge[i].x);
		int fy = find(edge[i].y);
		if(fx == fy)
			continue;
		vis[edge[i].x]++;
		vis[edge[i].y]++;
		fa[fx] = fy;
		ans += edge[i].z;
		if(vis[edge[i].x] == 1 && edge[i].x > n)
			continue;
		cnt++;
	}
	printf("%d",ans);
	return 0;
}

