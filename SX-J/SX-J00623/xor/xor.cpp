#include <bits/stdc++.h>
using namespace std;
int n, k, a[100000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	cout << a[2];
	return 0;
}
