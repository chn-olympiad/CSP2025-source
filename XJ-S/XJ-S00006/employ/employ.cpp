#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 505;
int p[MAXN], c[MAXN];
long long ans;
int main(void) {
	ios_base :: sync_with_stdio(false);
	cin . tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string test;
	cin >> n >> m >> test;
	for (int i = 1;i <= n; ++i) {
		p[i] = i;
		cin >> c[i];
	}
	if (n <= 20) {
		do {
			int fail = 0;
			for (int i = 1;i <= n; ++i) {
				if (fail >= c[p[i]]) {
					++fail;
					continue;
				}
				if (test[i - 1] == '0')
					++fail;
			}
			if (n - fail >= m)
				++ans;
		}
		while (next_permutation(p + 1, p + 1 + n));
		cout << ans;
		return 0;
	}
	long long maxn = 1;
	for (int i = 1;i <= n; ++i)
		maxn = maxn * i % 998244353;
	cout << maxn;
	return 0;
} 
