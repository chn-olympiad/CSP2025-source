#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
template<typename TY>
inline void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	s = x * f;
}
struct edge{
	int u,v; ll w;
}E[N*4];
int f[N],n,m,k;
ll c[N],a[15][N];
ll ans;
int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
bool cmp(edge a,edge b){
	return a.w < b.w;
}
void solve1(){
	sort(E+1,E+m+1,cmp);
	int u,v; ll w;
	int cnt =0;
	for(int i=1;i<=m;i++){
		u = find(E[i].u),v = find(E[i].v), w = E[i].w;
		if(u == v) continue;
		f[v] = u; ans += w; 	
		if(++cnt >= n - 1) break;
	}
	cout << ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n); read(m); read(k);
	int u,v; ll w;
	for(int i=1;i<=m;i++){
		read(u); read(v); read(w);	
		E[i] = {u,v,w};
	}
	for(int i=1;i<=n;i++) f[i] = i;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j]);
		}
	}
	if(k == 0){
		solve1();
		return 0;
	}
	vector<edge> slp;
	for(int i=1;i<=m;i++){
		slp.push_back({E[i].u,E[i].v,E[i].w});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int p=j+1;p<=n;p++){
				slp.push_back({j,p,a[i][j] + a[i][p]});
			}
		}
	}
	sort(slp.begin(),slp.end(),cmp);
	ll len = slp.size(),cnt = 0;
	for(int i=0;i<len;i++){
		u = find(slp[i].u),v = find(slp[i].v),w = slp[i].w;
		if(u == v) continue;
		f[v] = u; ans += w;
		if(++cnt >= n - 1) break;
	}
	cout << ans;
	return 0;
}
