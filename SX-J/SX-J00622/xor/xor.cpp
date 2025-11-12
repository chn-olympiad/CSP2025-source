#include <bits/stdc++.h>
using namespace std;

int n;

unsigned long long k, ans = 0;

struct number {
	unsigned long long num;
	bool ifyh = 0;
} a[500430];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].num;
	for (int i = 2; i <= n; i++) {
		a[i].num = (a[i].num ^a[i - 1].num);
	}
	for (int i = 1; i <= n; i++) {
		if ((a[i].num ^ a[i - 1].num) == k) {
			ans++;
			a[i].ifyh = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((a[j].num ^ a[i - 1].num) == k) {
				int cnt;
				for (cnt = i; cnt <= j; cnt++) {
					if (a[cnt].ifyh) {
						a[i].ifyh = 1;
						break;
					}
				}
				if (!a[i].ifyh)
					ans++;
				if (!a[i].ifyh)
					i = j + 1;
				else
					i = cnt;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}