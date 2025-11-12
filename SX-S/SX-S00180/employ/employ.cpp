#include <bits/stdc++.h>
using namespace std;
string s;
int a[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, k = 0, l = 0;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		if (s[1] == '0')
			k++;
		for (int i = 1; i < n; i++) {
			if (a[i] > k)
				l++;
			if (s[i] == 0)
				k++;
		}
		if (a[n] > k)
			l++;
		cout << l;
	} else if (m == n) {
		if (s[1] == '0')
			k++;
		for (int i = 1; i < n; i++) {
			if (a[i] > k)
				l++;
			if (s[i] == 0)
				k++;
		}
		if (a[n] > k)
			l++;
		if (l != n)
			cout << 0;
		else
			cout << 1;
	} else
		cout << n*n;
	return 0;
}