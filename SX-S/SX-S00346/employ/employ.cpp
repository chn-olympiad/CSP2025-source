#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	long long sum = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum *= i;
		sum %= 998244353;
	}
	cout << sum;
	return 0;
}
