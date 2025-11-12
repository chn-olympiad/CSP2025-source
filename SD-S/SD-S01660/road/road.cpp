//LUOGU UID 1208546

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
struct edge {
	int u,v,w;
}a[N];
vector<edge> vec;
int f[N],n,m,k,ans=0,cnt=0;
int p[11][N],c[11];
bool vis[11];
inline int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline bool cmp(edge x,edge y) {
	return x.w<y.w;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>p[i][j];
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++) {
		if(find(a[i].u)!=find(a[i].v)) {
			f[find(a[i].u)]=find(a[i].v);
			cnt++;
			ans+=a[i].w;
		}
		if(cnt==n-1) break;
	}
	cout<<cnt<<endl;
	return 0;
}


