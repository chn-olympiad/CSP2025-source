#include <bits/stdc++.h>
using namespace std;
int k = 0, b[1000006];
string a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[++k] = int(a[i] - '0');
		}

	}
	sort(b + 1, b + k + 1);
	for (int i = k; i >= 1; i--)
		cout << b[i];
	return 0;
}