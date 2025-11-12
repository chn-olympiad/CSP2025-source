#include <bits/stdc++.h>
using namespace std;
int a1[1000005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a1[i];
	int ans = a1[1];
	int n1 = 0, m1 = 0;
	sort(a1 + 1, a1 + n *m + 1);
	int ans1 = 0;
	for (int i = n * m; i >= 1; i--) {
		if (a1[i] == ans) {
			ans1 = i;
			break;
		}
	}
	ans1 = n * m - ans1 + 1;
	n1 = 1, m1 = 0;
	int n2 = 0;
	for (int i = 1; i <= ans1; i++) {
		if (n2 < n)
			n2++;
		else {
			n1++;
			n2 = 1;
		}

	}
	if (n1 % 2 == 0)
		m1 = n - ans1 % n + 1;
	else
		m1 = ans1 % n;
	if (m1 == 0)
		m1 = n;
	cout << n1 << " " << m1;

	return 0;
}
