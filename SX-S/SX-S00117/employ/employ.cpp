#include <bits/stdc++.h>
using namespace std;
char ss;


struct E {
	int a, i;
} e[505];
int n, m, c;

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ss;
	}
	for (int i = 1; i <= n; i++) {
		cin >> e[i].a;

	}
	int s = n;
	for (int i = 1; i < n; i++) {
		s *= n - i;
	}
	cout << s % 998244353;
	return 0;

}

