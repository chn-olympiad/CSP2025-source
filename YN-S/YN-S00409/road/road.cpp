#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

class UF {
	private:
	vector<int> parent;
	vector<int> rank;
	
	public:
	UF(int n) {
		parent.resize(n+1);
		rank.resize(n+1,0);
		for (int i=1;i<=n;i++) {
			parent[i]=i;
		}
	}
	
	int find(int x) {
		if (parent[x]!=x) {
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}
	
	bool Union(int a,int b) {
		int rootA=find(a);
		int rootB=find(b);
		if (rootA==rootB) return false;
		if (rank[rootA]<rank[rootB]) {
			parent[rootA]=rootB;
		}else if (rank[rootB]<rank[rootA]) {
			parent[rootB]=rootA;
		}else {
			parent[rootA]=rootB;
			rank[rootB]++;
		}
		return true;
	}
	
};

ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') {
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}

struct node {
	ll u,v,w;
	bool operator < (const node&other) const {
		return w < other.w;
	}
};

vector<node> G;
vector<vector<ll>> cs;
ll costs[12][2];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ll n=read(),m=read(),k=read();
	G.resize(m+1);
	cs.resize(k+1,vector<ll>(n+1));
	
	for (int i=1;i<=m;i++) {
		int u=read(),v=read(),w=read();
		G.push_back({u,v,w});
	}
	sort(G.begin(),G.end());
	
	for (int i=1;i<=k;i++) {
		costs[i][1]+=read();
		for (int j=1;j<=n;j++) cs[i][j]=read();
	}
	
	UF uf(n);
	ll ans=0;
	for (node it:G) {
		if (uf.Union(it.u,it.v)) {
			if (it.u<=k || it.v<=k) {
				if (it.u<=k && it.v<=k) {
					costs[it.u][1]+=min(cs[it.u][it.v],cs[it.v][it.u]);
					costs[it.v][1]+=min(cs[it.u][it.v],cs[it.v][it.u]);
					costs[it.u][0]+=it.w;
					costs[it.v][0]+=it.w;
				}else {
					if (it.u<=k) {
						costs[it.u][1]+=cs[it.u][it.v];
						costs[it.u][0]+=it.w;
					}else {
						costs[it.v][1]+=cs[it.v][it.u];
						costs[it.v][0]+=it.w;
					}
				}
				
			}
		}
	}
	
	for (int i=1;i<=n;i++) {
		if (uf.find(i)==i) {
			ll Add=1e18;
			for (int j=1;j<=k;j++) {
				Add=min(cs[j][i],Add);
			}
			ans+=Add;
		}
	}
	
	for (int i=1;i<=k;i++) {
		ans+=min(costs[i][0],costs[i][1]);
	}
	cout<<ans<<endl;
	
	return 0;
}