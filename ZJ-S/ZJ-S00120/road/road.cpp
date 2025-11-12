#include<bits/stdc++.h>
using namespace std;
unsigned int dis[10005][10005],cost[11][10005],now[10005];
int n,m,k,ans=0;
bool vis[10005];
int read() {
	int sgn=0,ret=0,ch=getchar();
	while(!isdigit(ch))sgn|=(ch=='-'),ch=getchar();
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
void prim() {
	now[0]=0;
	vis[0]=1;
	int s,cnt=0;
	while(cnt<n) {
		unsigned int mindis=4e9;
		for(int i=0; i<n; i++)if(mindis>now[i]&&(!vis[i]))mindis=now[i],s=i;
		cnt++;
		ans+=now[s];
		vis[s]=1;
		now[s]=0;

		for(int i=0; i<n; i++) {
			if(i==s)continue;
			cout<<"";
			now[i]=min(now[i],dis[s][i]);
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,255,sizeof(dis));
	memset(now,255,sizeof(now));
	n=read(),m=read(),k=read();
	for(int i=0; i<m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=w;
	}
	for(int i=0; i<k; i++) {
		cost[i][0]=read();
		for(int j=1; j<=n; j++) {
			cost[i][j]=read();
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j) {
				dis[i][j]=INT_MAX;
				continue;
			}
			for(int l=0; l<k; l++) {
				dis[i][j]=min(dis[i][j],cost[l][0]+cost[l][i+1]+cost[l][j+1]);
			}
		}
	}
	prim();
	cout<<ans;
}
