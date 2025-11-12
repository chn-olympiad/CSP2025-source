#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin >> n;
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
		sum %= 998244353;
	}
	cout << sum % 998244353;
}