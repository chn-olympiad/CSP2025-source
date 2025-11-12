#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int f,t,s;
} b[1000005];
bool cmp(node a,node b) {
	return a.s<b.s;
}
vector<pair<int,int> >g[500];
int a[100][1000],c[100];
bool vis[100000];
signed main() {
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cnt=0,n,m,k;
	cin>>n>>m>>k;
	for(int i=1,u,v,w; i<=m; i++) {
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		b[++cnt].f=v,b[cnt].t=u,b[cnt].s=w;
	}
	bool flag=1;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			if(a[i][j]!=0)flag=0;
		}
	}
	if(flag) {
		cout<<0;
		return 0;
	}
	int ans=0;
	sort(b+1,b+m+1,cmp);
	for(int i=1; i<=m; i++) {
		if(vis[b[i].f]==0&&vis[b[i].t]==0) {
			ans+=b[i].s;
			vis[b[i].f]=vis[b[i].t]=1;
		}
	}
	cout<<ans;

	return 0;
}
