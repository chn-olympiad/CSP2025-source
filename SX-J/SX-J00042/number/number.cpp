#include <bits/stdc++.h>
using namespace std;
string a;

int b[100005], cnt, maxx = INT_MIN;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[++cnt] = a[i] - '0';
		}
	}
	sort(b + 1, b + 1 + cnt);
	for (int i = cnt; i > 0; i--) {
		cout << b[i];
	}
	return 0;
}
