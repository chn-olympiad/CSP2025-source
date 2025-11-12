#include <bits/stdc++.h>
using namespace std;
string a;
int l, d, t = 0, b[1000005], m = 1;

bool cmp(int q, int h) {
	return q > h;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	l = a.size();
	for (int i = 0; i < l; i++) {
		if (a[i] >= '0' and a[i] <= '9') {
			b[t] = a[i] - '0';
			t++;
		}
	}
	sort(b + 1, b + t + 1, cmp);
	if (b[0] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < t; i++)
		cout << b[i];
	return 0;
}
