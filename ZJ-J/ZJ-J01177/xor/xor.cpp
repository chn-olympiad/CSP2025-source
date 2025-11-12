#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 5e5 + 10, M = 2e6 + 10;
int n, k, a[N], sum, ans;
bool vis[M];
queue<int> q;
signed main() {
	File("xor");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	vis[0] = 1;
	for (int i = 1; i <= n; i ++) {
		sum ^= a[i];
		if (vis[sum ^ k]) {
			sum = 0, ans ++;
			while (!q.empty()) {
				vis[q.front()] = 0, q.pop();
			}
		}
		if (sum != 0) q.push(sum);
		vis[sum] = 1;
	}
	cout << ans << endl;
	return 0;
}
