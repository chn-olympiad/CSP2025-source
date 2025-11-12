#include <bits/stdc++.h>
using namespace std;
int a[11111111];
int f[111111];
int din[1111][1111];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] ^ a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (a[i] == k)
			din[i][i]++;
		for (int j = i + 1; j <= n; j++) {
			if ((f[j]^f[i - 1] ) == k)
				din[i][j]++;

		}
	}
	for (int i = 1; i <= n; i++) {
		bool flag = false;
		for (int j = 1; j <= n; j++) {
			if (din[i][j] > 0)
				flag = true;
			//cout << din[i][j] << " ";
		}
		//cout << endl;
		if (flag == true)
			ans++;
	}
	for (int j = 1; j <= n; j++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (din[i][j] > 0)
				cnt++;
		}
		if (cnt > 1 && (ans - cnt + 1) > 0)
			ans = ans - cnt + 1;
	}
	cout << ans << endl;
}
