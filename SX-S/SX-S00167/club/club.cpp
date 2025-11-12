#include <bits/stdc++.h>
using namespace std;
int num[100005], num1[100005], num2[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a, s;
			cin >> num[i] >> num1[i] >> num2[i];
		}
		if (n == 2) {
			int a = max(num[1], max(num1[1], num2[1]));
			int b = max(num[2], max(num1[2], num2[2]));
			cout << a + b << endl;
			continue;
		}
		sort(num + 1, num + n + 1);
		for (int i = n; i >= n - n / 2 + 1; i--)
			cnt += num[i];
		cout << cnt << endl;
		for (int i = 1; i <= 2 * n; i++)
			num[i] = 0;
	}
	return 0;
}
