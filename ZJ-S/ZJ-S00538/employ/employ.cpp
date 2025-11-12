#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define N 505
#define MOD 998244353
int n, m, a[N];
long long f[N];
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int one = 0;
	for (int i = 0; i < n; ++i)
		one += s[i] - '0';
	if (m == n) {
		sort(a, a + n);
		for (int i = 0; i < n; ++i)
			if (s[i] == '0') {
				puts("0");
				return 0;
			}
		if (a[0] == 0) {
			puts("0");
			return 0;
		}
		long long ans = 1;
		for (long long i = 2; i <= n; ++i)
			(ans *= i) %= MOD;
		cout << ans << endl;
	} else {
		vector<int> seq(n, 0);
		for (int i = 0; i < n; ++i)
			seq[i] = i;
		int ans = 0;
		do {
			int cur = 0;
			for (int i = 0; i < n; ++i)
				if (cur >= a[seq[i]] || s[i] =='0')
					++cur;
			(ans += (n - cur >= m)) %= MOD;
		} while (next_permutation(seq.begin(), seq.end()));
		cout << ans << endl;
	}
	return 0;
}
