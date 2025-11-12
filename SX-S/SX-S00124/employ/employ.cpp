#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define i128 __int128_t
#define endl '\n'
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 998244353;
const int MaxN = 1e9;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
		sum %= INF;
	}
	cout << sum;
	return 0;//???这题是人？为什么不对？？？
}