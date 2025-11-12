#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n;
int a[5010];
int ans = 0;
int v[5010];
bitset<5010> q;
map<long long, bool> Eps;

void aaa(int x, int l, int m) {
	if (!Eps[q.to_ulong()]) {
		Eps[q.to_ulong()] = true;
		if (l > 2 * m) {
			ans++;
		}
		ans %= N;
		return;
	}
	for (int i = x; i <= n; i++) {
		if (v[i])
			continue;
		v[i] = true;
		q[i] = 1;
		aaa(i, l + a[i], max(m, a[i]));
		q[i] = 0;
		v[i] = false;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n < 3) {
		cout << "0";
		return 0;
	}
	aaa(1, 0, 0);
	printf("%d", ans);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			if()
//			f[i][j]+=f[i-1][j];
//		}
//	}
	return 0;
}