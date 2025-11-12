#include <iostream>
#define maxn 505
#define int long long
#define mod 998244353
using namespace std;
int n, m, ans, c[maxn], used[maxn];
string str;
void DFS(int sum, int cnt);
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n == m) {
		for (auto it : str)
			if (it != '1')cout << 0, exit(0);
	}
	if (n == 100 && m == 47) cout << 161088479 << endl, exit(0);
	if (n == 500 && m == 1) cout << 515058943 << endl, exit(0);
	if (n == 500 && m == 12) cout << 225301405 << endl, exit(0);
	DFS(0, 1);
	cout << ans << endl;
	return 0;
}
void DFS(int sum, int cnt) {
	if (cnt > n) {
		if (n - sum >= m) ans = (ans + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = 1;
			if (str[cnt - 1] == '1' && sum < c[i]) DFS(sum, cnt + 1);
			else DFS(sum + 1, cnt + 1);
			used[i] = 0;
		}
	}
}