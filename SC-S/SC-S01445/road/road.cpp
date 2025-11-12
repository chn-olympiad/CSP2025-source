#include<bits/stdc++.h>
using namespace std;
struct node {
	int v,l;
};
const int N=1e+6+20,M=1e+4+5;
queue<node> dl;
bool operator>(node &a,node &b) {
	return a.l<b.l;
}
vector<node> G[N];
bool color[M+20];
int dis[M+20];
bool bj[M+20];
int main() {
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	while(m--) {
		int u,v,l;
		cin>>u>>v>>l;
		G[u].push_back({v,l});
		G[v].push_back({u,l});
	}
	for(int j=1;j<=k;j++) {
		int xz;
		cin>>xz;
		for(int i=1; i<=n; i++) {
			int q;
			cin>>q;
			G[n+j].push_back({i,q});
			G[i].push_back({n+j,q+xz});
		}
	}
	for(int i=1;i<=n+k;i++){
		dis[i]=INT_MAX;
	}
	dl.push({1,0});
	color[1]=true;
	dis[1]=0;
	while(!dl.empty()){
		node h;
		h=dl.front();
		dl.pop();
		color[h.v]=true;
		bj[h.v]=false;
		for(int i=0;i<G[h.v].size();i++){
			node yy=G[h.v][i];
			if(color[yy.v]) continue;
			if(dis[yy.v]>=dis[h.v]+yy.l){
				dis[yy.v]=/*dis[h.v]+*/yy.l;
				if(!bj[yy.v]&&!color[yy.v]){
					dl.push({yy.v,/*dis[h.v]+*/yy.l});
					bj[h.v]=true;
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/