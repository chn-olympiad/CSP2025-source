#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+27;
const int MAXM=1e6+27;

int n,m,k;
long long c[11][MAXN];
int fa[MAXN];

struct Edge {
	int u,v;
	long long w;
} e[MAXM];

int get(int u) {
	if(fa[u]==u) return u;
	else return fa[u]=get(fa[u]);
}

long long kruscal() {
	long long ans=0;
	int rd=0;
	for(int i=1; i<=n; i++)
		fa[i]=i;
	for(int i=1; i<=m,rd<n-1; i++) {
		int fu=get(e[i].u),fv=get(e[i].v);
		if(fu==fv) continue;
		ans+=e[i].w;
		fa[fu]=fa[fv];
		rd++;
	}
	return ans;
}

bool cmp(Edge x,Edge y) {
	return x.w<y.w;
}


int main() {

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
		cin>>e[i].u>>e[i].v>>e[i].w;

	sort(e+1,e+m+1,cmp);

	for(int i=1; i<=k; i++) {
		cin>>c[i][0];
		for(int j=1; j<=n; j++)
			cin>>c[i][j];
	}
	
	
	long long ans=kruscal();
	
	cout<<ans<<endl;
	return 0;
}