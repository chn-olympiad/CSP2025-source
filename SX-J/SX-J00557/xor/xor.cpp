#include <bits/stdc++.h>
using namespace std;
int a[(int)5e5+5], sum[(int)5e5+5];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			ans++;
	}
	if (k == 0) {
		cout << ans;
		return 0;
	}
	int l = 1, r = n;
	while (l <= r) {
		int zh;
		for (int i = l; i <= r; i++) {
			if (zh == k) {
				ans++;
				l = i + 1;
				break;
			}
			if (a[i] == k)
				break;
			else {
				int ez = zh, ea = a[i];
				string sz, sa;
				while (ez >= 1) {
					if (ez % 2 == 0) {
						sz += '0';
					} else {
						sz += '1';
					}
					ez /= 2;
				}
				while (ea >= 1) {
					if (ea % 2 == 0) {
						sa += '0';
					} else {
						sa += '1';
					}
					ea /= 2;
				}
				while (sa.size() != sz.size()) {
					if (sa.size() > sz.size())
						sz += '1';
					else
						sa += '1';
				}
				string nwe;
				for (int j = 0; j < sa.size(); j++) {
					if (sa[i] == '1' && sz[i] == '1')
						nwe += '1';
					else
						nwe += '0';
				}
				zh = 0;
				for (int j = 0; j < nwe.size(); j++) {
					if (nwe[j] == 1) {
						int cj = 1;
						for (int z = 1; z <= (int)nwe.size() - j; z++)
							cj *= 2;
						zh += cj;
					}
				}
			}
		}
		l++;
	}
	cout << ans;
	return 0;
}
