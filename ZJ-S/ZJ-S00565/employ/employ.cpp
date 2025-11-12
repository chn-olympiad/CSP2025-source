#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans, a[100100], b[100100], vis[100100];
char str[100100];
void get() {
	int t = 0, i, k = 0;
	for (i = 1; i <= n; ++i) {
		if(str[i - 1] == '1' && t < a[b[i]]) ++k;
		else if(str[i - 1] == '1') ++t;
		else t += 1 - (str[i - 1] - '0');
		if(k >= m) break;
	}
	if(k >= m) ++ans;
}
int pp;
void dfs(int t) {
	if(t > n) {
		get();
		return ;
	}
	for (int i = 1; i <= n; ++i)
		if(!vis[i]) {
			b[t] = i;
			vis[i] = 1;
			dfs(t + 1);
			vis[i] = 0;
		}
}
signed main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf ("%lld %lld %s", &n, &m, str);
	for (int i = 1; i <= n; ++i) scanf ("%lld", &a[i]);
	dfs(1);
	printf ("%lld", ans);
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
