#include <bits/stdc++.h>
using namespace std;
char a[1000008];
int b[1000008];

int f(int e) {
	if (e == 0)
		return 1;
	else {
		long long g = 1;
		for (int i = 1; i <= e; i++) {
			g = g * 10;
		}
		return g;
	}

}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.size();
	int n = 0;
	for (int i = 0; i < l; i++) {
		a[i] = s[i];
		if (a[i] >= '0' && a[i] <= '9' ) {
			b[i] = a[i] - '0';
			n++;
		}
	}
	sort(b, b + n + 1);
	long long ans = 0, e = 0;
	for (int j = 1; j <= n; j++) {
		ans += b[j] * f(e);
		e ++;
	}
	cout << ans;
	return 0;
}
