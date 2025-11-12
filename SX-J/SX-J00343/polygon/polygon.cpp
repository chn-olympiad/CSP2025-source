#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ll s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 3; i <= n; i++) {
		s += n / i%998244353;
	}
	cout << s;
	return 0;
}
