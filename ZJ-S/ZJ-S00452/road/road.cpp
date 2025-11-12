#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,b[15],c[15][1005],f[1005],ans,cnt;
struct sjx {
	int u,v,w;
} a[1000005];
int cmp(sjx x,sjx y) {
	return x.w<y.w;
}
int find(int x) {
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1; i<=k; i++) {
		cin>>b[i];
		for(int j=1; j=n; j++)
			cin>>c[i][j];
	}
	for(int i=1; i<=n; i++)
		f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1; i<=m; i++) {
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y)continue;
		f[x]=y;
		ans+=a[i].w;
		cnt++;
		if(cnt==n-1) {
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
//csprp++;