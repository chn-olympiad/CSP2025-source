#include<bits/stdc++.h>
using namespace std;
const int N=1e3+505;
int n,m,k;
struct Node {
	int to,val;
}s[N*100];
vector<Node>q[N];
int c[15],a[15][N],in[N];
bool vis[N],flag[15];
long long d[N],ans;
long long mp[N][N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(vis,127,sizeof mp);
	for(int i=1; i<=m; i++) {
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
	}
	memset(vis,false,sizeof vis);
	bool f1=true;
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		if(c[i]!=0) f1=false;
		for(int j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
			q[i+n].push_back({j,a[i][j]});
			q[j].push_back({i+n,a[i][j]});
		}
	}
	if(k==0) {
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=0;
				if(mp[i][j]<1e9){
					maxn=max(maxn,mp[i][j]);
					ans+=mp[i][j];
				}
			}
		}
		cout<<ans-2*maxn;
	}

	return 0;
}

