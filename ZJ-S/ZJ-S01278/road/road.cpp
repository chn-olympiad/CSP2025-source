#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m,k;
int c[15],a[15][N];
int vis[N];
map<int,int> mp[N];
queue<int> p[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=w;
		vis[u]++,vis[v]++;
		p[u].push(v);
		p[v].push(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
//			if(mp[u][v]) mp[{u,v}]=min(mp[{u,v}],a[i][j]);
		}
	}
	if(k==0){
		ll sum=0;
		for(int i=1;i<=n;i++){
			while(!p[i].empty()){
				if(vis[p[i].front()]==1) sum+=mp[i][p[i].front()];
				p[i].pop();	
			}	
		}
		cout<<sum;
	}
	else
		cout<<0;
	return 0;
} 
