#include <bits/stdc++.h>
using namespace std;
const int MAXM=1e6+5,MAXN=1e4+5;
struct node{
	int v,nxt;
	long long w;
}e[MAXM<<1];
int p[MAXN],tot=0,n,m,k;
long long c[15],W[15][MAXN],Min=1e18;
void addedge(int u,int v,int w){
	e[++tot].v=v;
	e[tot].nxt=p[u];
	e[tot].w=w;
	p[u]=tot;
}
bool flag[MAXN];
/*void dfs(int cnt,int lst){
	long long sum=0;
	e[tot]
	for(int i=lst+1;i<=k;i++){
		flag[i]=1;
		dfs(cnt+1,i);
		tot-=add;
		flag[i]=0;
	}
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	bool oka=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			oka=0;
		}
		for(int j=1;j<=n;j++){
			cin>>W[i][j];
			if(W[i][j]!=0){
				oka=0;
			}
		}
	}
	if(oka){
		cout<<0;
		return 0;
	}
	return 0;
}
