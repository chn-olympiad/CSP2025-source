#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
long long ans, ans1 = 1;
long long a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (a[n] == 1) {
		for (int i = 3; i <= n; i++) {
			long long num = n;
			ans1 = 1;
			long long num1 = 1;
			for (int j = 1; j <= min(i, n - i); j++)
				num1 *= j;
			for (int j = 1; j <= min(i, n - i); j++) {
				ans1 *= num;
				num--;
				ans1 %= 998244353;
			}
			ans += ans1;
			ans /= num1;
		}
		cout << ans;
		return 0;
	}
	if (a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3])))
		cout << 1;
	else
		cout << 0;
	return 0;
}



