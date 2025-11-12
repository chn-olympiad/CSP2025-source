#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4 + 10,M = 2e6 + 10,P = 1e18;

struct node{
	int u,v,w;
	friend bool operator > (const node &a,const node &b){
		return a.w < b.w;
	}
	friend bool operator < (const node &a,const node &b){
		return a.w > b.w;
	}
} tmp[M];

priority_queue<node> e,d;
int n,m,k,p,u,v,w,nn,mm,ans = 1e18,f[N],h[N],a[20][N];

int find(int u){
	if(f[u] == u) return u;
	return f[u] = find(f[u]);
}

bool merge(int u,int v){
	u = find(u),v = find(v);
	if(u == v) return 1;
	if(h[u] > h[v]) swap(u,v);
	f[u] = v;
	return 0;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		e.push(node{u,v,w});
	}
	for(int i = 1;i <= k;i++)
		for(int j = 0;j <= n;j++)
			scanf("%lld",&a[i][j]);
	nn = n,mm = m;
	d.push(node{0,0,P});
	for(int s = 0;s < (1 << k);s++){
		int num = 0;
		for(int i = 1;i <= k;i++)
			if((s >> (i - 1)) & 1){
				n++;num += a[i][0];
				for(int j = 1;j <= nn;j++)
					d.push(node{n,j,a[i][j]});
				if(num >= ans) break;
			}
		for(int i = 1;i <= n;i++)
			f[i] = i,h[i] = 1;
		int cur = 0,ku = 0;
		while(ku != n - 1){
			if(num >= ans) break;
			int u,v,w;
			if(d.top().w < e.top().w){
				u = d.top().u,v = d.top().v,w = d.top().w;
				d.pop();
			}
			else{
				tmp[++cur] = e.top();
				u = e.top().u,v = e.top().v,w = e.top().w;
				e.pop();
			}
			if(merge(u,v)) continue;
			num += w,ku++;
		}
		for(int i = 1;i <= cur;i++)
			e.push(tmp[i]);
		ans = min(ans,num);n = nn;
		while(d.size() > 1) d.pop();
	}
	printf("%lld\n",ans);
	return 0;
}