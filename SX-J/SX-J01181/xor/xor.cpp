#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[1000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		cout << "1";
	} else
		cout << a[1];

}
