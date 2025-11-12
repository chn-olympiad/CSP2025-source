#include <bits/stdc++.h>
using namespace std;
string a;
char b[10000];
long long s = 0;
long long x, y;
long long i;

bool cmp(int m, int n) {
	return m > n;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for ( i = 0; i <= a.size() - 1; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[s] = a[i];
			s++;
		}
	}
	sort(b, b + s, cmp);
	for ( i = 0; i <= s - 1; i++)
		cout << b[i];
}
