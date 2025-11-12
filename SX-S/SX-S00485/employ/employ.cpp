#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[505];
string s;
int sum;
long long ans = 1, last;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];



	for (int j = 1; j <= n; j++) {
		ans *= j;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}
