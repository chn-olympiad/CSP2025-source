#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const int N=1e4+5,M=2e6+3;

struct Grugh{
	int fm,to,w,nod;//,nt head[N],
}edge[M];

int vis[N]={},idx=0;

int n,m,k;
lint sn,sw,cost=0;

void addedge(int fm,int to,int w,int nw){
//	u<v 
	edge[++idx]={fm,to,w,nw};
}

bool cmp1(Grugh p,Grugh q){
//	nod=0
	return p.w<q.w;
}

void lcm(){
	int u,v,w;
	for(int i=1;i<=idx;i++){
		
		u=edge[i].fm;
		v=edge[i].to;
		w=edge[i].w;
		
		if((u<=n&&!vis[u])||(v<=n&&!vis[v])){
			vis[u]=1;
			vis[v]=1;
			cost+=w;
		}
		
	}
	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int u,v,w,nod; cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		addedge(u,v,w,0);
	}
	
	if(!k){
		sort(edge+1,edge+1+idx,cmp1);
		lcm();
		cout<<cost;
		
		return 0;
	}
	
	sn=sw=0;
	for(int i=1;i<=k;i++){
		cin>>nod;
		sn+=nod;
		for(int j=1;j<=n;j++){
			cin>>w;
			sw+=w;
			addedge(j,n+k,w,nod);
		}
	}
//	cout<<sn<<" "<<sw;
	if(!sn){
		sort(edge+1,edge+1+idx,cmp1);
		lcm();
		cout<<cost;
		return 0;
	}
	if(!sn&&!sw){
		cout<<0;
		return 0;
	}
	
	return 0;
}