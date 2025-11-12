#include <bits/stdc++.h>
using namespace std;
int a[3][100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof a);
		int n, s = 0;
		cin >> n;
		vector<int>f(n);
		f[0] = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		sort(a[0] + 1, a[0] + n + 1, [](int a, int b) {
			return a > b;
		});
		for (int i = 1; i <= n / 2; i++)
			s += a[0][i];
		cout << s << endl;
	}
	return 0;
}