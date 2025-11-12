#include<bits/stdc++.h>
using namespace std;
struct dat{
	int v;
	long long w;
};
long long g[10005][10005];
long long c[15];
long long cv[15][10005];
long long dis[10005][15];
bool vis[10005];
int sd;
//operator priology q;
void dj(int s,int n){
	queue<int>q;
	for(int i = 2;i<=n;i++){
		
		vis[i] = 1;
		for(int j = 0;j<=sd;j++){
			dis[i][j] = 1e17;
		}
	}
	dis[s][0] = 0;
	vis[s] = 0;
	
	q.push(1);
	
	while(!q.empty()){
		int v = q.front();
		//long long w = q.front().w;
		q.pop();
		int k = 0;
		for(int e = 1;e<=n;e++)
		{
			if(e!=v&&vis[e]==1){
				
				if(dis[e][k]>(dis[v][k]+g[e][v])){
					//cout<<"awdawdawd";
					dis[e][k]=dis[v][k]+g[v][e];
					//cout<<v<<" "<<dis[v][k];
					q.push(e);
					vis[e] = 0;
					
					
				}
				if(k<sd){
					
					if(dis[e][k]>dis[v][k]){
						dis[e][k+1]=dis[v][k];
						k++;
						
						q.push(e);
						vis[e] = 0;
						
					}
				}
			}

		}

	}
	
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	cin>>n>>m>>sd;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)
		{
			if(i!=j){
				g[i][j] =  1e17;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x][y] = z;
		g[y][x] = z;
	}
	for(int i = 1;i<=sd;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			cin>>cv[i][j];
		}
	}
	dj(1,n);
	long long ans = 1e17;
	for(int i = 0;i<=sd;i++){
		ans = min(ans,dis[n][i]);
	}
	cout<<ans;
	return 0;
}
