#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool flag = false;
int n, k;

int main() {
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n % 2 == 0)
		cout << n / 2;
	else
		cout << (n - 1) / 2;
	return 0;
}
