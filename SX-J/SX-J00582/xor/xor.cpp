#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005];
long long ans, t, q;
long long visited[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		if (a[i] == k) {
			ans++;
			visited[i] = 1;
		}

	}
	for (long long i = 1 ; i <= n ; i++) {
		t = a[i];
		if (visited[i] == 1)
			continue;
		for (long long j = i + 1 ; j <= n ; j++) {
			if (visited[j] == 1)
				break;
			t = (a[j] ^ t);
			//cout << t << "-" << a[i] << "-" << a[j] << " ";
			if (t == k) {
				ans++;
				i = j + 1;
				break;
			}

		}
		//cout << "\n";
	}
	cout << ans;
	return 0;
}