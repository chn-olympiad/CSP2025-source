#include<bits/stdc++.h>
using namespace std;

const int N=10015;//n
int n,m,k;
int u,v,w;
int c[N][15];
int x,y,ans;

int fa[N];
int sum[N];
int find(int x) {
	if(x==fa[x])return x;
	sum[fa[x]]+=sum[x];
	fa[x]=find(fa[x]);
	sum[x]=sum[fa[x]];
	return fa[x];
}
struct man {
	int u,v;
	int w;
} a[2000005];
bool cp(man x,man y) {
	return x.w<y.w;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
		fa[i]=i;
		sum[i]=1;
	}
	for(int i=1; i<=m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
		//vec[u].push_back(v);
	}
	ans=0;
	sort(a+1,a+m+1,cp);
	for(int i=1; i<=m; i++) {
		x=a[i].u,y=a[i].v;
		if(find(x)!=find(y)) {
			ans+=a[i].w;
			//if(a[i].w==6)cout<<fa[x]<<' '<<fa[y]<<endl;
			//cout<<ans<<'\n';
			if(sum[find(x)]>=sum[find(y)])
			fa[y]=fa[x];
			else fa[x]=fa[y];
		}

	}
	cout<<ans;
//	for(int i=1; i<=k; i++) {
//		cin>>c[i][0];
//		for(int j=1; j<=n; j++) {
//			cin>>c[i][j];
//		}
//	}
	return 0;
}
/*
5 8 2

1 4 6
2 3 7
4 2 5
4 3 4

1 5 1
2 5 8
3 5 2
4 5 4

1 1 8 2 4


*/

