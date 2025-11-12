#include <bits/stdc++.h>
using namespace std;
string a;
int j = 0, k = 0;
int c[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int b = a.size();
	for (int i = 0; i < b + 1; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			c[k] = a[i] - '0';
			k++;
		}
	}
	k++;
	sort(c, c + k );

	for (int i = k - 1; i > 0; i--) {
		cout << c[i];
	}
	return 0;
}
