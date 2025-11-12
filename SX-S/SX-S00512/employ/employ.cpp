#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ll n;
	cin >> n;
	ll sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	cout << sum;
	return 0;
}
