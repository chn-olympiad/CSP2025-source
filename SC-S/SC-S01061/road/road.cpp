#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;

int n,m,k;
vector<pair<int,int>> g[MAXN];
bool vis[MAXN];
int c[MAXN],a[MAXN][MAXN];


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		g[ui].push_back({vi,wi});
		g[vi].push_back({ui,wi});
	} 
	
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	
	ll ans=0;

	memset(vis,0,sizeof(vis)); 
	
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			for(auto t:g[i]){
				int v=t.first,wei=t.second;
				if(v==i)	continue;
				if(!vis[v]){
					if(a[j][v]<=wei){
						ans+=a[j][v];
						vis[j]=true;
					}
					else{
						ans+=wei;
					}
					vis[v]=true;
				}
			}
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}
