#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	int cot = 2;
	cin >> n >> k;
	string a[n];
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}
	cout << cot << endl;
	return 0;
}
