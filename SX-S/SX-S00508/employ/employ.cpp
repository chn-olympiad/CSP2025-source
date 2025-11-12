#include <bits/stdc++.h>
using namespace std;
int a[1111111];
int b[1111111];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, k;
	long long ans = 1;
	cin >> n >> k;
	cin >> s;
	for (int i = i; i <= k; i++) {
		ans = ans * n % 998244353;
		n--;
	}
	cout << ans << endl;
}