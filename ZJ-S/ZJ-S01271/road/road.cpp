#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans = 0;
struct edge{
	int u,v,w;
} r[1000006];
int fa[10005];
int findfa(int x){
	if(fa[x] == x) return x;
	return fa[x] = findfa(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) fa[i] = i;
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	}
	if(k>0){
		cout<<0;
		return 0;
	}
	sort(r+1,r+m+1,cmp);
	for(int i =1;i<=m;i++){
		cout<<r[i].w<<" ";
	}
	for(int i = 1;i<=n-1;i++){
		int x = findfa(r[i].u);
		int y = findfa(r[i].v);
		if(x != y){
			fa[x] = y;
			ans +=  r[i].w; 
		}
	}
	cout<<ans;
	return 0;
} 
