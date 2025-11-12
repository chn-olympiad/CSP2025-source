#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define reg(i, x, y, step) for (int i = x; i <= y; i += step)
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
int a[N], ans = INT_MIN;
int n, k;
bool flag = 0;
signed main() {
	File("xor");
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	bool ne = 1;
	for (int j = 1; j <= n; j++) {
		int cnt = 0;
		for (int i = j; i <= n + 1; i++) {
			if (sum == k && !ne) {
				cnt++;
				sum = 0;
				ne = 1;
			}
			if (i > n) break;
			if (sum == 0) sum = a[i], ne = 0;
			else sum ^= a[i], ne = 0;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
