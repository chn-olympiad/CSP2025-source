#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
long long ans=0;
long long road[N][N],r[20][N],g[20],fang[20];
bool st[N],flag[N];
long long dis[N],disg[N];
void prim(){
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	for(int l=1;l<=n;l++){
		int t=0;
		for(int i=1;i<=n;i++){
			if(st[i]==0&&(t==0||dis[t]>dis[i]))t=i;
		}
		st[t]=1;
		int gg=disg[t];
		ans+=dis[t];
		for(int i=1;i<=n;i++){
			if(disg[i]==gg&&gg!=0){dis[i]-=g[gg];disg[i]=0;}
			if(dis[i]>=road[t][i]){
				dis[i]=road[t][i];
				disg[i]=0;
			}
		}
		if(gg)g[gg]=0;
		for(int j=1;j<=k;j++){
			for(int i=1;i<=n;i++){
				if(dis[i]>=g[j]+r[j][t]+r[j][i]){
					dis[i]=g[j]+r[j][t]+r[j][i];
					disg[i]=j;
				}
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(road,0x3f,sizeof(road));
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		if(road[u][v]>w)road[u][v]=road[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>g[i];
		fang[i]=g[i];
		for(int j=1;j<=n;j++)cin>>r[i][j];
	}
	prim();
	cout<<ans;
	return 0;
}
