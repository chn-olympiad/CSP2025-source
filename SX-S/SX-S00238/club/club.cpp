#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sum1, sum2, sum3, ans1, ans2, ans3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		int n;
		cin >> n;
		int b = n / 2;
		for (int j = 1; j <= n; j++) {
			int x, y, z;
			cin >> x >> y >> z;
			int maxn = max(x, max(y, z));
			if (maxn == x) {
				sum1++;
				ans1 += x;
			}
			if (maxn == y) {
				sum2++;
				ans2 += y;
			}
			if (maxn == z) {
				sum3++;
				ans3 += z;
			}
		}
		if (sum1 <= b && sum2 <= b && sum3 <= b)
			cout << ans1 + ans2 + ans3 << ' ' << sum1 << endl;
		else
			cout << 0;
		sum1 = sum2 = sum3 = ans1 = ans2 = ans3 = 0;
	}
	return 0;
}
