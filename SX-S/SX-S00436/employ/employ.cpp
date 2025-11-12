#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n;
long long h = 1;

int main() {
	fast;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		h *= i;
	}
	cout << h % 998244353;
	return 0;
}