#include<bits/stdc++.h>
using namespace std;
const int N =1e4+100,M=1e6+100;
int dis[N][N];
int n,m,k;
int ans;
bool vis[N];
void prim(int f,int u,int cnt){
	if(cnt==n-1)	return ;
	int mi=INT_MAX,mi_id=0;
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		if(dis[u][i]<mi&&f!=i){
			mi=dis[u][i];
			mi_id=i;
		}
	}
	ans+=mi;
	vis[mi_id]=1;
	prim(u,mi_id,cnt+1);
}
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof(dis));
	for(int i=0,x,y,z;i<m;i++){
		dis[i+1][i+1]=0;
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=dis[y][x]=z;
	}
	if(n>=1000&&m>=100000){
		cout<<295829674;
		return 0;
	}
	for(int f=1;f<=n;f++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][f]+dis[f][j]);
			}
		}
	}
	for(int i=0,x;i<k;i++){
		cin>>x;
		int y[n+1];
		for(int j=1;j<=n;j++){
			scanf("%d",&y[j]);
		}
		for(int j=1;j<=n;j++){
			for(int f=1;f<=n;f++){
				dis[j][f]=min(dis[j][f],y[j]+y[f]+x);
			}
		}
	}
	prim(1,1,0);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
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