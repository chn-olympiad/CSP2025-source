#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
const int INF=0x3f3f3f3f;
int n,m,k;
struct node{
	int to;
	int nxt;
	int w;
}edge[N];
int head[N],top=0;
int c[M];
int a[11][N];
int va=0;
bool vis[N];
void add(int u,int v,int w){
	edge[++top].to=v;
	edge[top].nxt=head[u];
	edge[top].w=w;
	top++;
}
void cg(int u,int w){
	for(int i=head[u];i;i=edge[i].nxt){
		if(edge[i].w>=a[w][u]+a[w][edge[i].to]+c[w]){
			edge[i].w=a[w][u]+a[w][edge[i].to];
			va+=c[w];
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flag=1;
		}
		for(int k=1;k=n;i++){
			if(!vis[k]){
				vis[i]=1;
				cg(k,i);
			}
			
		}
	}
	if(flag==0){
		cout<<0<<"\n";
		return 0; 
	}
	return 0;
}

