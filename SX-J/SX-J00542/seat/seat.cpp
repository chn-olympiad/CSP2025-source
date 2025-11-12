#include <bits/stdc++.h>
using namespace std;
long long n, m, s, a[1000], ans, m2, s1 = 1, s2 = 1;
bool k;

bool cmp(int a1, int b2) {
	return a1 > b2;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	m2 = n * m;
	cin >> s;
	a[1] = s;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + m2 + 1, cmp);
	for (int i = 1; i <= m2; i++) {
		if (a[i] == s) {
			ans = i;
		}
	}
	for (int i = 1; i < ans; i++) {
		if (!k) {
			if (s2 == n) {
				k = 1;
				s1++;
			} else
				s2++;
		} else {
			if (s2 == 1) {
				k = 0;
				s1++;
			} else
				s2--;
		}
	}
	cout << s1 << " " << s2;
	return 0;
}
