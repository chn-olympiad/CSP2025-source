#include<bits/stdc++.h>
using namespace std;
int fa[1000020] , used[20];
struct edge{
	int f , e , w;	
	void input(){
		cin >> f >> e >> w;
		return;
	}
}ed[1000010];
bool cmp(edge a , edge b){
	return a.w < b.w;
}
int tot;
int fi(int x){
	return x == fa[x] ? x : fi(fa[x]);
}

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		ed[++tot].input();
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			ed[++tot].f = i + n;
			ed[++tot].e = j;
			ed[++tot].w = x;
		}
	}
	long long sum = n + k , ans = 0;
	for(int i = 1; i <= sum; i++) fa[i] = i;
	sort(ed + 1 , ed + tot + 1 , cmp);
	for(int i = 1; i <= tot; i++){
		if(fi(ed[i].f) != fi(ed[i].e)){
			ans += ed[i].w;
			fa[fa[ed[i].f]] = fa[ed[i].e];
			sum--;
		}
		if(sum == 1) break;
	}
	cout << ans;
	return 0;
}