#include <bits/stdc++.h>
using namespace std;
string a;
const int N = 1e6+10;
long long b[N];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long s = 0;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > 47 && a[i] < 58) {
			s++;
			b[s] = a[i] - '0';
		}
	}
	sort(b + 1, b + s + 1, cmp);
	for (int i = 1; i <= s; i++) {
		cout << b[i];
	}
	return 0;
}