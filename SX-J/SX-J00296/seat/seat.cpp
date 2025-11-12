#include <bits/stdc++.h>
using namespace std;
int a[10000005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, ming, ans, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum++;
			cin >> a[sum];
		}
	}
	ming = a[1];
	sort(a + 1, a + sum + 1);
	int t = 0;
	for (int i = sum; i >= 1; i--) {
		t++;
		if (a[i] == ming) {
			ans = t;
			break;
		}
	}
	if (ans <= n)
		cout << "1" << " " << ans;
	else {
		int line = ans / n;
		if (ans % n != 0)
			line += 1;
		if (line % 2 == 0)
			cout << line << " " << n - ans % n + 1;
		else
			cout << line << " " << ans % n;
	}

	return 0;
}