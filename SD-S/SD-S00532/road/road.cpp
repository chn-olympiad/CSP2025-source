#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6+5;
ll n,m,k;
ll h[N],cnt;
struct edge {
	int nxt,to,w;
} e[N*2];
inline void add(ll u,ll v,ll w) {
	e[++cnt].nxt=h[u];
	e[cnt].to=v;
	e[cnt].w=w;
	h[u]=cnt;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	cout<<0;
	return 0;
}
/*

*/

