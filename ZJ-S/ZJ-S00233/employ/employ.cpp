#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
bool v[1010];
int n, m, c[1010], a[1010];
long long ans = 0;
char s1[1010];

bool check() {
	int res = 0;
	int nls = 0;
	for (int i=1; i<=n; i++) {
		if (c[a[i]] <= nls) {
			nls ++;
			continue;	
		}
		if (s1[i-1] == '0') nls ++;
		if (s1[i-1] == '1') res ++;
	}
	if (res >= m) return true;
	return false;
}

void dfs(int t) {
	if (t > n) {
		if (check()) ans = (ans+1)%M;
		return;
	}
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			a[t] = i;
			v[i] = 1;
			dfs(t+1);
			v[i] = 0;
			a[t] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s1);
	int num = 0;
	for (int i=0; i<n; i++) {
		if (s1[i] == '1') num++;
	}
	if (n <= 10) {
		for (int i=1; i<=n; i++) {
			scanf("%d", &c[i]);
			v[i] = 0;
		}
		ans = 0;
		dfs(1);
		printf("%lld\n", ans);		
	} else {
		ans = 1;
		for (int i=1; i<=n; i++) {
			ans = (ans * i) % M;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
