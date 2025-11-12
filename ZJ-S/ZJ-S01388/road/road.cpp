#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int i,Z;
};
bool operator <(node a,node b){
	return a.Z>b.Z;
}
struct edge{
	int v,val,nxt;
}e[5000010];
int h[20010],totot=0,intr[20010],ans=LONG_LONG_MAX,sf[20010],jl[20010],www[20][20010],qnzs;
void prim(){
	memset(intr,0,sizeof intr);
	memset(jl,0x1f,sizeof jl);
	priority_queue<node>k;
	k.push({1,0});
	jl[1]=0;
	int anses=0;
	while(!k.empty()){
		node sj=k.top();
		k.pop();
		if(intr[sj.i])continue;
		intr[sj.i]=1;
		anses+=sj.Z;
//		cout<<sj.i<<' '<<sj.Z<<endl;
		for(int p=h[sj.i];p;p=e[p].nxt){
			int v=e[p].v,val=e[p].val;
			if(sf[v]==0)continue;
			if(jl[v]>val){
				jl[v]=val;
				k.push({v,val});
			}
		}
	}
//	cout<<"jeshu\n";
	ans=min(ans,anses);
}
void dfs(int deep){
//	cout<<deep<<endl;
	if(deep>n+k)prim();
	else dfs(deep+1),sf[deep]=sf[deep+k]=1,dfs(deep+1),sf[deep]=sf[deep+k]=0;
}
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++totot]={v,w,h[u]},h[u]=totot;
		e[++totot]={u,w,h[v]},h[v]=totot;
	}
	for(int i=1;i<=n;i++){
		sf[i]=1;
	}
	for(int i=1;i<=k;i++){
		int mi=LONG_LONG_MAX;
		cin>>www[i][0];
		for(int j=1;j<=n;j++){
			cin>>www[i][j];
			mi=min(mi,www[i][j]);
		}
		for(int j=1;j<=n;j++){
			if(www[i][j]==mi){
				for(int l=1;l<=n;l++){
					int u=j,v=l,w=www[i][l]+www[i][0];
					e[++totot]={v,w,h[u]},h[u]=totot;
					e[++totot]={u,w,h[v]},h[v]=totot;
				}
			}
		}
	}
	//cerr<<"ok";
	//dfs(n+1);
	prim();
	cout<<ans;
}
