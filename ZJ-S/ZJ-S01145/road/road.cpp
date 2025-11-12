#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,m,k,a[N],tw[N],cnt=0;
vector<pii> g[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		tw[++cnt]=w;
	}
	bool flag=false;
	for (int i=1;i<=k;i++){
		cin>>c[n+i];
		bool f=false;
		if(c[i]==0) f=true;
		int w;
		for (int j=1;j<=n;j++){
			cin>>w;
			if(w==0) f=false;
			tw[++cnt]=w;
			g[c[n+i]].push_back({j,w});
			g[j].push_back({c[n+i],w});
		}
		if(f) flag=true;
	}
	if(flag) cout<<0;
	sort(tw+1,tw+1+cnt);
	int ans=0;
	for (int i=1;i<n;i++){
		ans+=tw[i];
	}
	cout<<ans;
	return 0;
}