#include <bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=1000005;
int n,m,kk;
int l[N][N];
struct node{
	int c;
	int a[N];
}q[15];
int dis[N];
bool vis[N];
int ls[N];
int ans;
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			l[i][j]=2e9+5;
		}
		dis[i]=2e9+5;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>kk;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		l[u][v]=l[v][u]=min(l[u][v],w);
	}
	for(int i=1;i<=kk;i++){
		scanf("%d",q[i].c);
		for(int j=1;j<=n;j++){
			scanf("%d",q[i].a[j]);
		}
	}
	for(int k=1;k<=kk;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				l[i][j]=min(l[i][j],q[k].a[i]+q[k].a[j]);
			}
		}
	}
	int s=1;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=2;j<=n;j++){
			if(dis[j]<dis[k]&&vis[j]==0){
				k=j;
			}
		}
		vis[k]=1;
		ans+=ls[k];
		for(int j=1;j<=n;j++){
			if(dis[j]>dis[k]+l[k][j]){
				dis[j]=dis[k]+l[k][j];
				ls[j]=l[k][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
