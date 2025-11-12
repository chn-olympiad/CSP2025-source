#include <bits/stdc++.h>
#define MAXN 10010
#define INF 1000000100
#define mp city
using namespace std;
int n,m,K;
int city[MAXN][MAXN],c[MAXN][MAXN];
int res;
bool vis[1000],isfind[1000];
int road[1000],roadw[1000],nxtpos,nxtw,roadnum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)city[i][j]=0;
			else city[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		city[u][v]=city[v][u]=min(city[u][v],w);
	}
	for(int j=1;j<=K;j++){
		scanf("%d",&c[j][0]);
		for(int i=1;i<=n;i++){
			scanf("%d",&c[j][i]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int s=1;s<=K;s++)
			city[i][j]=city[j][i]=min(city[i][j],c[s][i]+c[s][j]+c[s][0]);
		}
	}
	vis[1]=1;
	road[1]=1;
	int last=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){//寻找新的可走边 
			if(vis[j]||isfind[j]||mp[last][j]==INF)continue;
			road[++roadnum]=j;
			roadw[roadnum]=mp[i][j];
			//cout<<"[DEBUG]"<<road[roadnum]<<" "<<roadw[roadnum]<<endl;
		}
		int minn=INF-10;nxtw=0;
		for(int j=1;j<=roadnum;j++){//寻找最短可走边 
			if(minn>roadw[j]){
				minn=roadw[j];
				nxtpos=j;nxtw=minn;
				isfind[j]=1;
			}
		}
		vis[nxtpos]=1;
		res+=roadw[nxtpos];
		road[nxtpos]=roadw[nxtpos]=INF;
		last=nxtpos;
		//cout<<"[DEBUG]"<<nxtpos<<" "<<nxtw<<endl;
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

