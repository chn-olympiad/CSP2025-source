#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N];
int n, m;
int sum ;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m = 1) {
		for (int i = 1; i <= n; i++) {
			sum *= i;
			cout << sum % 998244353;
			return 0;
		}
	}
	return 0;
}