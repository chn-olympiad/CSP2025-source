#include<bits/stdc++.h>
using namespace std;
long long n, a[5555], sum = 1;
int main () {
//	freopen ("polygon.in", "r", stdin);
//	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], sum *= a[i], sum %= 998244353;
	cout << sum;
	return 0;
}
