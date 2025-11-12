#include <bits/stdc++.h>
using namespace std; 
long long f(long long a) {
	if(a == 1)
		return 1;
	return a * f(a-1) % 998244353;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	cout << fac(m); 
	return 0;
}
