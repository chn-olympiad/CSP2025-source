#include <bits/stdc++.h>
using namespace std;
int n, m, k, u;
string s;
int a[505];

bool cmp(int num1, int num2) {
	if (num1 > num2)
		return 0;
	else
		return 1;
}

int main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		if (a[i]  m)
//			k++;
	}
	sort(a, a + n, cmp);
	for (int i = n; i >= n - m; i--) {
		u *= a[i];
	}

	cout << u;
	return 0;
}