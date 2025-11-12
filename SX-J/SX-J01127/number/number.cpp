#include <bits/stdc++.h>
using namespace std;

bool px(long long a, long long b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	long long t = 0;
	long long b[100009];
	cin >> a;
	for (long long i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[t] = a[i] - '0';
			t++;
		}
	}
	sort(b, b + t, px);
	for (long long i = 0; i < t; i++) {
		cout << b[i];
	}
}