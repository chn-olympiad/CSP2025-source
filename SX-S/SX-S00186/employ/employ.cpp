#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 998244353;
ll sum = 1;
ll n, m, aaa;
string a;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> a;
	for (int i = 1; i <= n; i++) {
		cin >> aaa;
	}
	for (int i = 1; i <= n; i++) {
		sum *= i;
		sum %= M;
	}
	cout << sum;
	return 0;
}
