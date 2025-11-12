#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
struct node{
	int u, v;
	long long qz;
}bian[M];
int fa[N];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int read(){
	int s = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return s;
}
bool cmp(node a, node b){
	return a.qz < b.qz;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		bian[i].u = read();
		bian[i].v = read();
		bian[i].qz = read();
	}
	long long ans = 0;
	sort(bian + 1, bian + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		if(find(bian[i].u) == find(bian[i].v)) continue;
		ans += bian[i].qz;
		fa[find(bian[i].v)] = bian[i].u;
	}
	cout << ans;
	return 0;
}
//15.14 k <= 10, wow!
//15.30 I give up, and I'll come back, go and see;
//17.09 I solved T3, now I'm back!!!!;
//17.44 I think T4 is easier;
