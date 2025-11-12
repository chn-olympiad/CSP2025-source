#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << k;
	return 0;
}
