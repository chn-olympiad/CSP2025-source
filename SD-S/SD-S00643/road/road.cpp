#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 10;
const long long M = 1e6 + 10;
const long long K = 20;
long long n,m,k;
long long ans = 0;
long long fa[N],v[K],build[K][N],minn[N][K];
bool vis[K],visedge[N][K];
struct Edge {
	long long _l,_r;
	long long cst;
	bool operator < (const Edge _x_) const {
		return cst < _x_.cst;
	}
};
vector<Edge> vec;

long long FInd(long long _x) {
	return _x == fa[_x] ? _x : (fa[_x] = FInd(fa[_x]));
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(vis,false,sizeof vis);
	memset(visedge,false,sizeof visedge);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (long long i = 1;i <= m;i ++) {
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		vec.push_back((Edge){u,v,w});
	}
	stable_sort(vec.begin(),vec.end());
	for (long long i = 1;i <= k;i ++) {
		scanf("%lld",&v[i]);
		for (long long j = 1;j <= n;j ++) {
			scanf("%lld",&build[i][j]);
		}
	}
	for (long long i = 1;i <= n;i ++) 
		fa[i] = i;
	for (long long i = 1;i <= n;i ++) {
		for (long long j = 1;j <= k;j ++) {
			minn[i][j] = build[j][i];
		}
	}
	for (auto s : vec) {
		long long faL = FInd(s._l),faR = FInd(s._r);
		if (faL == faR) 
			continue;
		long long now = s.cst,pos = 0;
		for (long long i = 1;i <= k;i ++) {
			if (vis[i]) {
				now = min(now,(!visedge[faL][i])*minn[faL][i]+(!visedge[faR][i])*minn[faR][i]);
			}
			else {
				if (now >= minn[faL][i] + minn[faR][i] + v[i]) {
					now = minn[faL][i] + minn[faR][i] + v[i];
					pos = i;
				}
			}
		}
		if (pos != 0) {
			vis[pos] = true;
			visedge[faR][pos] = true;
		}
		ans += now;
		for (long long i = 1;i <= k;i ++) {
			visedge[faR][i] = (visedge[faR][i] | visedge[faL][i]);
			minn[faR][i] = min(minn[faR][i],minn[faL][i]);
		}
		fa[faL] = faR;
	}
	printf("%lld\n",ans);
	return 0;
}
