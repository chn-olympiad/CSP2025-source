#include <bits/stdc++.h>
using namespace std;

int n, m, a, b[1000], cnt, flag;
long long ans = 1;

void jiecheng(int x, int y) {
	for (int i = x; i <= y; i++) {
		ans = (ans *i) % 998244353;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int k = n;
	for (int i = 1; i <= k; ++i)
		cin >> a;
	for (int i = 1; i <= k; ++i) {
		cin >> b[i];
		if (b[i] <= cnt) {
			n--;
			cnt++;
		}
	}
	while (1) {
		flag = 0;
		for (int i = 1; i <= k; ++i) {
			if (b[i] > 0 && b[i] <= cnt) {
				n--;
				cnt++;
				flag = 1;
				b[i] = 0;
			}
		}
		if (flag == 0)
			break;
	}
	jiecheng(n - m, n);
	cout << ans << endl;
	return 0;
}
