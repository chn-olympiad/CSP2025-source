#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int>PII;
const int N=1e6+2;
int h[N],e[N],w[N],ne[N];
int idx;
priority_queue<PII,vector<PII>,greater<int>>q;
void add(int u,int v,int c){
	e[idx]=v;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;	
}
int dist[N];
void di(int s)
{
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push({})	
}
int main()
{
	int n,m,k;
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		if(c==0){
			for(int j=1;j<=n;j++){
				cin>>x;
				add(0,j,x);
				add(j,0,x);
			}
		}
	}
	di(0);
} 
