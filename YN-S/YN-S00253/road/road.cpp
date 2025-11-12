#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5000;
#define ll long long
int n,m,k;
int fa[N];
int dis[N];
int flag=0;
bool v[N];
int head[N];
ll ans=0;
ll len[N];
struct tre{
	int to;
	int w;
	int nxt;
}edge[N];
struct node{
	int c;
	int ww[N];
}con[15];
void build(int u,int v,int w){
	edge[++flag]={v,w,head[u]};
	head[u]=flag;
	edge[++flag]={u,w,head[v]};
	head[v]=flag;
}
int gfa(int x){
	if(fa[x]==x) return x;
	dis[x]+=dis[fa[x]];
	return fa[x]=gfa(fa[x]);
}
void pt(){
	for(int i=1;i<=n;i++){
		v[i]=1;
		int res=1e9;
		for(int j=head[i];;j=edge[j].nxt){
			v[edge[j].to] ? 
			666:res=min(res,edge[j].w);
		}
		ans+=res;
	}
	cout<<ans;
}
/*
4 4 0
1 2 5
2 3 7
3 4 5
1 4 2
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) head[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		build(u,v,w);
	}
	if(k==0){
		pt();return 0;
	}
//	for(int i=1;i<=k;i++){
//		node t;
//		cin>>t.c;
//		for(int i=1;i<=n;i++) cin>>t.ww[i];
//		con[i]=t;
//	}
//	
	cout<<ans;
	return 0;
}