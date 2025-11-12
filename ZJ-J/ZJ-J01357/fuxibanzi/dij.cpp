#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,dis;
};
bool operator <(node a,node b){
	return a.dis>b.dis;
}
int tototto=0,dis[1000010],h[1000010];
int n,m;
struct edge{
	int v,val,nxt;
}e[1000010];
void add(int u,int v,int w){e[++tototto]={v,w,h[u]},h[u]=tototto;}
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	
priority_queue<node>q;
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(dis[u.u]!=u.dis)continue;
		for(int p=h[u.u];p;p=e[p].nxt){
			if(dis[e[p].v]>u.dis+e[p].val){
				dis[e[p].v]=u.dis+e[p].val;
				q.push({e[p].v,dis[e[p].v]});
			}
		}
	}
}
main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;add(u,v,w);
	}
	dij(1);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<endl;
	}
}
