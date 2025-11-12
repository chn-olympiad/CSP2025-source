#include<bits/stdc++.h>
using namespace std;
const int N=10000010;
struct Edge{
	int u,v;
	unsigned long long w;
}edge[N];
int fa[N],n,m,k;
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
	return;
}
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int g[20][N];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			cin>>g[j][i];
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				m++;
				edge[m].u=i;
				edge[m].v=k;
				edge[m].w=g[j][i]+g[j][0]+g[j][k];
			}
		}
	}
	sort(edge+1,edge+1+m,cmp);
	init();
	long long ans=0;
	for(int i=1;i<=m;i++){
		int a=edge[i].u,b=edge[i].v;
		int ta=find(a),tb=find(b);
		if(ta!=tb){
			fa[tb]=ta;
			ans=ans+edge[i].w;
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
