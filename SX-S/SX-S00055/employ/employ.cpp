#include <bits/stdc++.h>
using namespace std;
const long long MAX = 998244353;
int n, m, c[510], ai = 0;
string a;

int jc(int x) {
	long long ans = 1;
	for (int i = x; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			ans %= MAX;
			ans *= i;
//		cout << ans << " ";
		}
	}
	return ans;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			ai++;
		}
	}
	cout << ai << " ";
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	sort(c, c + n);
//	for (int i = 1; i <= n; i++) {
//		cout << c[i] << " ";
//	}
	if (ai == n) {
		cout << jc(n);
	} else if (ai <= 18) {
		cout << jc(n);
	}
	return 0;
}