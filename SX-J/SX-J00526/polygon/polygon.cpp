#include <bits/stdc++.h>
#define pushB emplace_back

using namespace std;
typedef long long ll;

int n, a[5010];
ll ans;
const int P = 998244353;

bool valid(vector<int> &vc, int sz) {
	ll sum = 0;
	for (int i = 1; i < sz; i++)
		sum += vc[i];
	return sum > vc[sz];
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);

	// 假设 a 数组升序排好序
	// sigma(a, 1, n) > 2 * max(a, 1, n)
	// sigma(a, 1, n - 1) > max(a, 1, n)

	sort(a + 1, a + n + 1);

	for (int len = 3; len <= n; len++)
		for (int l = 1; l <= n - len + 1; l++) {
			vector<int> vc(1);
			for (int i = l; i <= l + len - 1; i++)
				vc.pushB(a[i]);
			if (valid(vc, len)) {
				ans = (ans + 1) % P;
//				for (int i = 1; i <= len; i++)
//					printf("%d ", vc[i]);
//				puts("");
			}
		}

	printf("%lld\n", ans);
}