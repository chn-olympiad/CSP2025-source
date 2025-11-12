#include<bits/stdc++.h>
#define N 10010
#define piib pair<int,pair<int,bool>>
#define pb push_back
#define mp make_pair
#define fi() first()
#define sc() second()
using namespace std;
int n,m,k,c[11],f[11],ans=0;
vector<piib> g[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(mp(v,mp(w,0)));
		g[v].pb(mp(u,mp(w,0)));
		if(u%3==1) ans-=w;
		else ans+=w;
		ans=max(2*v,ans);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[i+n].pb(mp(j,mp(w,0)));
			g[j].pb(mp(i+n,mp(w,0)));
			if((i+j)%3==1) ans-=w;
			else ans+=w;
			ans=max(2*j,ans);
		}
	}
	cout<<ans;
	return 0;
}

