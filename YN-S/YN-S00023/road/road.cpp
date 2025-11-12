#include<bits/stdc++.h>

using namespace std;
bool vis[10001][10001];
struct city {
	int u,v;
	long long w;
} x[1000001];
struct countryside {
	long long c,a[10001];
} y[11];
bool cmp(city s1,city s2) {
	return s1.w<s2.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>x[i].u>>x[i].v>>x[i].w;
	}
	sort(x+1,x+m+1,cmp);
	for(int i=1; i<=k; i++) {
		cin>>y[i].c;
		for(int j=1; j<=n; j++) {
			cin>>y[i].a[j];
		}
	}
	vis[x[1].u][x[1].v]=true;
	vis[x[1].v][x[1].u]=true;
	ans+=x[1].w;
	for(int i=2; i<=m; i++) {
		if(!vis[x[i].u][x[i].v]) {
			ans+=x[i].w;
			vis[x[i].u][x[i].v]=true;
			vis[x[i].v][x[i].u]=true;
			for(int j=1; j<=n; j++) {
				if(vis[x[i].u][j]) {
					vis[x[i].v][j]=true;
					vis[j][x[i].v]=true;
				}
				if(vis[x[i].v][j]) {
					vis[x[i].u][j]=true;
					vis[j][x[i].u]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}