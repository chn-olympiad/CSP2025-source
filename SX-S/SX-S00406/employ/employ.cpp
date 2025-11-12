#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, s[505], a[505];
char c;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c, s[i] = c - '0';
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << ans;
}