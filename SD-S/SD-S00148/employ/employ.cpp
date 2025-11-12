#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 510;
const int mod = 998244353;
int n, m, a[N], c[N], p[N];
ll res;
bool b[N];

void dfs(int it) {
	if(it == n + 1) {
		int now = 0, tot = 0;
		for(int i = 1; i <= n; i++) {
			if(now >= c[p[i]]) ++now;
			else {
				if(a[i]) ++tot;
				else ++now;
			}
		}
		if(tot >= m) res = (res + 1) % mod;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!b[i]) {
			b[i] = 1;
			p[it] = i;
			dfs(it + 1);
			b[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%1d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%1d", &c[i]);
	dfs(1);
	printf("%lld\n", res);
	return 0;
}
