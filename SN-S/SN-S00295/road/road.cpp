#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
vector<int> g[1000010],c[1000010];
int a[20][10010];
bool tf[20];
int vis[10010],dis[10010];
bool js[10010];
int sy;
int ans;
queue<int> q;
void spfa(int s){
	q.push(s);
	vis[s]=1;
	js[s]=true;
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
	}
	dis[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int siz=g[x].size();
		for(int i=0;i<siz;i++){
			int minn=1e9;
			int x=-1,xf=-1;
			for(int j=1;j<=k;j++){
				if(a[j][0]+a[j][x]+a[j][g[x][i]]<minn){
					minn=a[j][0]+a[j][x]+a[j][g[x][i]];
					x=j;
					xf=1;
				}
				else if(tf[j]&&a[j][x]+a[j][g[x][i]]<minn){
					minn=a[j][x]+a[j][g[x][i]];
					x=j;
					xf=-1;
				}
			}
			int minx=min(minn,min(c[x][i],dis[g[x][i]]));
			if(minx==c[x][i]){
				dis[g[x][i]]=dis[x]+c[x][i];
				if(vis[g[x][i]]==0){
					q.push(g[x][i]);
					vis[g[x][i]]=1;
				}
				sy--;
				if(sy<=0){
					cout<<ans;
					exit(0);
				}
			} 
			else if(minx==minn){
				if(xf==1){
					tf[x]=true;
				}
				dis[g[x][i]]=minn;
				if(vis[g[x][i]]==0){
					q.push(g[x][i]);
					vis[g[x][i]]=1;
				}
				sy--;
				if(sy<=0){
					cout<<ans;
					exit(0);
				}
			}
			else{
				ans+=dis[g[x][i]];
				sy--;
				if(sy<=0){
					cout<<ans;
					exit(0);
				}
			}
		}
	}
}
int sta=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u);
		c[u].push_back(w);
		c[v].push_back(w);
		if(i==1){
			sta=u;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sy=n;
	spfa(sta);
	cout<<ans;
	return 0;
}
