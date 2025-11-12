#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e4+10;
const int NN=1e3+10;
const int M=1e6+10;
struct edge {
	int u,v;
	long long w;
	bool operator < (const edge &p) const {
		return w<p.w;
	}
};
vector<edge>edges;
int vi[NN];
int fa[N];
long long mp[NN][NN];

int _find(int x) {
	if(x==fa[x])return x;
	return fa[x]=_find(fa[x]);
}
void _union(int x,int y) {
	int fx=_find(x),fy=_find(y);
	fa[fx]=fy;
}
bool check(int x,int y) {
	return _find(x)==_find(y);
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)fa[i]=i;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
		edges.push_back({v,u,w});
	}
	if(k==0) {
		sort(edges.begin(),edges.end());
		long long cnt=0,ans=0;
		for(edge i:edges) {
			if(cnt==n-1)break;
			int u=i.u,v=i.v,w=i.w;
			if(check(u,v))continue;
			cnt++;
			_union(u,v);
			ans+=(long long )w;
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				mp[j][k]=1e18;
			}
		}
	for(int i=1; i<=k; i++) {
		int sssssssss;
		cin>>sssssssss;
		for(int j=1; j<=n; j++) {
			cin>>vi[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				mp[j][k]=min(mp[j][k],(long long)vi[j]+(long long )vi[k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			edges.push_back({i,j,mp[i][j]});
			edges.push_back({j,i,mp[i][j]});
		}
	}
	sort(edges.begin(),edges.end());
	long long cnt=0,ans=0;
	for(edge i:edges) {
		if(cnt==n-1)break;
		int u=i.u,v=i.v,w=i.w;
		if(check(u,v))continue;
		cnt++;
		_union(u,v);
		ans+=(long long )w;
	}
	cout<<ans;
	return 0;
}
