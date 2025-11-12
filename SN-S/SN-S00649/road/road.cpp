//SN-S00649 袁浩文 西安辅轮中学
#include <bits/stdc++.h> 
#define int long long
using namespace std;
cons int maxn=1e5+5;
int n,m,k,c[15],a[10004][15],cnt;
struct node{
	int id,dis;
};
vector<pair<int,int> >edge[maxn];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(cnt==k){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				edge[i].push_back({j,a[i][j]});
				
			}
		}
		priority_queue<node>q;
		
	}
}
