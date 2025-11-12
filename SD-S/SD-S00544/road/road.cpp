#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define debug
using namespace std;
const int N=1e4+1e1;
int n,m,k;
vector<pair<int,int> > e[N];
int c[N],a[15][N];
int vis[N],tot;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int u,v,w,i=1;i<=m;++i){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		vis[c[i]]=1,++tot;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]==0){vis[j]=1,++tot;continue;}
			e[c[i]].push_back({j,a[i][j]});
			e[j].push_back({c[i],a[i][j]});
		}
	}
	int cnt=0,ans=0;
	bool fl=0;
	while(tot<n){
		for(int u=1;u<=n;++u){
			if(!vis[u]){
				cnt=0x3f3f3f3f;
				for(int v=0;v<e[u].size();++v)
					cnt=min(cnt,e[u][v].second);
				if(cnt!=0x3f3f3f3f){
					ans+=cnt;
					vis[u]=1;
					++tot;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
