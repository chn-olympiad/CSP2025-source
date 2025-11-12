#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005];
int flag = 1, bom = 1, num1, num2, num3, st[500005], sm[500005];

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			flag = 0;
		if (a[i] != 1 && a[i] != 0)
			bom = 0;
		if (a[i] == 0)
			num1++;
		if (a[i] == 1 && a[i - 1] == 1 && st[i] == 0 && st[i - 1] == 0) {
			num2++;
			st[i] = st[i - 1] = 1;
		}
		if (a[i] == 0 && a[i - 1] == 1) {
			if (sm[i] == 0 && sm[i - 1] == 0) {
				num3++;
				sm[i] = sm[i - 1] = 1;
			}
		}
		if (a[i] == 1 && a[i - 1] == 0) {
			if (sm[i] == 0 && sm[i - 1] == 0) {
				num3++;
				sm[i] = sm[i - 1] = 1;
			}
		}
	}
	if (flag && k == 0)
		cout << n / 2;
	else if (bom && k == 0)
		cout << num1 + num2;
	else if (bom && k == 1)
		cout << num3;

	return 0;
}
