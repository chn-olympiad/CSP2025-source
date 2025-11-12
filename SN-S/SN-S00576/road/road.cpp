#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
int n,m,k,total=0,head[N];
long long ans=3e9;
struct node{
	int u,v,w,next;
}edge[M];

void init(int u,int v,int w){
	edge[++total].v=v;
	edge[total].w=w;
	edge[total].u=u;
	edge[total].next=head[u];
	head[u]=total;
}
int solve(){
	bool vis[N];
	bool vie[M];
	long long ans=0;
	queue<node>q;
	int mini=-1,minx=1e9;
	for(int i=1;i<=total;i++){
		if(edge[i].w<minx){
			minx=edge[i].w;
			mini=i;
		}
	}
	vie[mini]=true;
	vis[edge[mini].u]=true;
	vis[edge[mini].v]=true;
	q.push(edge[mini]);
	ans+=minx;
	while(!q.empty()){
		node e=q.front();
		q.pop();
		int u=e.u;
		int v=e.v;
		int mini=-1,minx=1e9;
		for(int k=u;k!=-1;k=edge[k].next){
			if(!vis[edge[k].v]){
				if(edge[k].w<minx){
					minx=edge[k].w;
					mini=k;
				}
			}
		}
		for(int k=v;k!=-1;k=edge[k].next){
			if(!vis[edge[k].v]){
				if(edge[k].w<minx){
					minx=edge[k].w;
					mini=k;
				}
			}
		}
		if(mini==-1)continue;
		vie[mini]=true;
		vis[edge[mini].u]=true;
		vis[edge[mini].v]=true;
		q.push(edge[mini]);
		ans+=minx;
		cout<<mini<<" "<<minx<<endl;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		init(u,v,w);
		init(v,u,w);
	}
	ans=solve();
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		if(c==0){
			for(int j=1;j<=n;j++){
				int w;
				cin>>w;
				init(n+i,j,w);
				init(j,n+i,w);
			} 
		}
		else{
			int w;
			for(int j=1;j<=n;j++){
				cin>>w;
			//	init(n+i,j,w);
				//init(j,n+i,w);
		//	} 
			//long long ans2=solve()+c;
		//if(ans>ans2){
			//	ans=ans2;
		//	}
		}
	}
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
