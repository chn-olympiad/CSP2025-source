#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int n, q;
unsigned long long sum = 1;
int main() {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	//不可以，总司令 
	cin >> n >> q;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		sum *= x;
	}
	int ans = sum % MOD;
	cout << ans << endl;
	return 0;
}