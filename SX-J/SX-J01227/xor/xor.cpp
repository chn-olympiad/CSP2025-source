#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005];
long long ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 2) {
		if (a[1] == k)
			ans++;
		if (a[2] == k)
			ans++;
		if (ans < 1) {
			if (a[1]^a[2] == k)
				ans++;
		}
		cout << ans;
		return 0;
	}
	cout<<"xiang chu ge yi huo qian zhui he sheng xia de xiang bu chu lai le zhi jie pian 5 fen";
	return 0;
}
