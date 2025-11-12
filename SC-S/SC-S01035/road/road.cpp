#include <bits/stdc++.h>
#define _all(i,a,b) for(int i = a; i <= b; i ++)
#define __all(i,a,b) for(int i = a; i < b; i ++)
#define r_all(i,a,b) for(int i = a; i >= b; i--)
#define vt vector<int>
#define vl vector<LL>
#define v2 vector<vt>
using namespace std;
using LL = long long ;
struct edge{
	int u,v,w;
	bool operator<(const edge & other) const{return w > other.w;}
};
int fa[int(1e4 + 30)];
int _find(int x){
	return fa[x] == x ? x : fa[x] = _find(fa[x]);
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	priority_queue<edge> q1,q2;
	vector<bool> vis(n+5,1);
	_all(i,1,m) cin>>u>>v>>w,q1.push({u,v,w});
	vt c(k+5),sz(n+5);
	v2 a(k+5,vt(n+5));
	_all(i,1,k){
		cin>>c[i];
		_all(j,1,n) cin>>a[i][j];
	}
	//二进制枚举1-1<<k
	LL ret = 1e18;
	_all(i,0,int(1<<(k-1))){ //选择修复升级哪些村子
		LL ans = 0;int j = i,cnt = 1,tp = n,ad = 0;
		_all(i,1,n) fa[i] = i,sz[i] = vis[i] = 1; //初始化并查集
		q2 = q1;
		while(j > 0) {
			if(j % 2){
				ans += c[cnt];//升级费用
				//可用边加入
				tp ++;
				_all(i,1,n) q2.push({i,tp,a[cnt][i]});
				fa[tp] = tp;
			}
			cnt ++;
			j >>= 1;
		}
		//最小生成树
		while(ad < n){
			auto i = q2.top();q2.pop();
			u = i.u,v = i.v,w = i.w;
			int du = _find(u),dv = _find(v);
			if(du == dv) continue;
			if(sz[dv] > sz[du]) swap(u,v);
			fa[du] = dv; //合并
			sz[du] += sz[dv];
			ans += w;
			if(ans > ret) break;
			if(vis[u] and u <= n) vis[u] = 0, ad ++;
			if(vis[v] and v <= n) vis[v] = 0, ad ++;
		}
		ret = min(ret,ans);
	}
	printf("%lld",ret);
	return 0;
}//freopen
// 2^k * nlogn