#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
struct edge{
	int v,w;
};
vector<edge> e[N];
int n,m,k,a,b,c,vis[N],t[20],cnt,s;
bool f[N];
long long tot,d[N],minn=1e10;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
		if(c<minn){
			minn=c;
			s=a;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>t[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			e[i+n].push_back({j,a});
			e[j].push_back({i+n,a});
		}
	}
	for(int i=0;i<=n+k;i++)
		d[i]=1e10;
	d[s]=0;
	for(int i=1;i<=n+k;i++){
		int u=0;
		for(int j=1;j<=n+k;j++){
			if(j<=n||(j>n&&f[j-n]==1)){
				if(vis[j]==0&&d[j]<d[u]){
					u=j;
				}
			}
			if(j>n&&f[j-n]==0){
				if(vis[j]==0&&d[j]+t[j-n]<d[u]){
					u=j;
				}
			}	
		}
		vis[u]=1;
		tot+=d[u];
		if(u<=n) cnt++;
		else if(f[u-n]==0){
			tot+=t[u-n];
			f[u-n]==1;
		}
		if(cnt==n) break;
		for(auto k:e[u]){
			int v=k.v;
			int w=k.w;
			if(d[v]>w)
				d[v]=w;
		}
	}  
	cout<<tot<<'\n';
	return 0;
} 