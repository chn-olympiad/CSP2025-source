#include <bits/stdc++.h>
using namespace std;
int b[1000005], l = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[l] = int(a[i] - '0');
			l++;
		}
	}
	sort(b + 1, b + l + 1);
	if (b[l] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = l; i > 1; i--)
		cout << b[i];
	return 0;
}
