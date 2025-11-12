#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, k, l, r, ans, max_ai;
int a[N], pre_xor[N], f[N];
bool check(int x) {
	int num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			f[j] = max(f[j], f[j - i] + (pre_xor[i] ^ pre_xor[j] == k));
		}
	}
	return f[n] >= x;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pre_xor[i] = pre_xor[i - 1] ^ a[i];
		max_ai = max(max_ai, a[i]);
	}
	if (k > n || k > max_ai) {
		printf("0");
		return 0;
	} else if (max_ai == 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) ans++, sum = 0;
			else if (a[i] == 1) {
				sum++;
				if (sum % 2 == 0) ans++;
				sum %= 2;
			}
		}
		printf("%lld", ans);
		return 0;
	} else if (k == 0) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) sum = 0, ans++;
			else sum ^= a[i];
		}
		printf("%lld", ans);
		return 0;
	}
	l = 1; r = n;
	while (l < r) {
		int mid = l + r >> 1;
		memset(f, 0, sizeof(f));
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%lld", ans - 1);
	return 0;
}