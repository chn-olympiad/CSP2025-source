#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,k;
}d[100100];
int f[10110],cnt,ans;
bool isk[15];
int cost[15];
int n,m,u,v,k,c,cntb;
int fa(int a){
	if(f[a] == a){
		return a;
	}
	f[a] = fa(f[a]);
	return f[a];
}
bool xt(int a, int b){
	if(fa(a) == fa(b)){
		return 1;
	}
	return 0;
}
void insert(int a,int b){
	f[fa(a)] = fa(b);
}
bool cmp(edge a,edge b){
	return a.k < b.k;
}
int main(){
	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	cin >> n >> m >> k;
	for(int i = 1;i <= n + k;i++){
		f[i] = i;
	}
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> c;
		d[++cnt] = {u,v,c};
	}
	sort(d + 1,d + 1 + m,cmp);
	for(int i = 1;i <= m;i++){
		if(!xt(d[i].u,d[i].v)){
			insert(d[i].u,d[i].v);
			cntb++;
			ans += d[i].k;
		}
	}
	cout << ans;
	return 0;
}

