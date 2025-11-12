#include<bits/stdc++.h>
#define lint long long
using namespace std;
int n,m,k,c[1001],p[101][20002],fa[20002];
lint ans;
struct edge{
	int u,v,w;
}e[2000002],oiiai;
int findd(int x){
	if(fa[x] == x) return x;
	return fa[x] = findd(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> p[i][j];
		}
	}
	for(int i = 1;i <= n;i++) fa[i] = i; 
	sort(e + 1,e + m + 1,cmp);
	int t = 0;
	for(int i = 1;i <= m;i++){
		int uu = findd(e[i].u);
		int vv = findd(e[i].v);
		if(uu == vv) continue;
		t++;
		fa[uu] = vv;
		ans += 1LL * e[i].w;
	}
	if(t < n - 1) cout << "???";
	else cout << ans;
	return 0;
}
