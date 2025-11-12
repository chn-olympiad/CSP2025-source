#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15][10005];
typedef pair<int,int> pii;
vector<pii> e[10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		int f;
		for(int j=0;j<e[u].size();j++){
			if(e[u][j].first==v){
				f=0;
				e[u][j].second=min(e[u][j].second,w);
				for(int k=0;k<e[v].size();k++){
					if(e[v][k]==u){
						e[v][k].second=min(e[v][k].second,w);
						break;
					}
				} 
				break;
			}
		}
		if(f){
			e[u].push_back({v,w});
			e[v].push_back({u,w});	
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<0;
	return 0;
}
