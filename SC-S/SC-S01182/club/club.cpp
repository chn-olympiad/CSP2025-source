#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
long long  t, n, g[N], maxn;
struct node{
	int a, b, c;
}m[N];
bool cmp(node x, node y){
	return x.a > y.a;
}
bool cmp1(node x, node y){
	if(x.a != y.a) return x.a > y.a;
	return x.b < y.b;
}
void dfs(int step, int x, int y, int z){
	if(step == n + 1){
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			if(g[i] == 1) ans += m[i].a;
			if(g[i] == 2) ans += m[i].b;
			if(g[i] == 3) ans += m[i].c;
		}
		maxn = max(maxn, ans);
		return ;
	}
	if(x + 1 <= n / 2){
		g[step] = 1;
		dfs(step + 1, x  + 1, y, z);
		g[step] = 0;
	}
	if(y + 1 <= n /2){
		g[step]= 2;
		dfs(step + 1, x, y + 1, z);
		g[step] = 0;
	}
	if(z + 1 <= n / 2){
		g[step] = 3;
		dfs(step + 1, x, y, z + 1);
		g[step] = 0;
	}
}
void solve(){
	cin >> n;
	bool flag2 = true, flag3 = true;
	for(int i = 1;i <= n;i++){
		cin >> m[i].a >> m[i].b >> m[i].c;
		if(m[i].b) flag2 = false;
		if(m[i].c) flag3 = false;
	}
	if(flag2 && flag3){
		maxn = 0;
		sort(m + 1, m + n + 1, cmp);
		for(int i = 1;i <= n / 2;i++){
			maxn += m[i].a;
		}
		cout << maxn << endl;
	}
	else if(flag3){
		maxn = 0;
		sort(m + 1, m + n + 1, cmp1);
		for(int i = 1;i <= n / 2;i++) maxn += m[i].a;
		for(int i = n / 2 + 1;i <= n;i++) maxn += m[i].b;  
		cout << maxn << endl;
	}
	else{
		maxn = 0;
		dfs(1, 0, 0, 0);
		cout << maxn << endl;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}