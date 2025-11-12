#include <bits/stdc++.h>
using namespace std;
char ms[505];
long long n, m, a = 0, sum = 1;

struct node {
	int bh, nx;
} k[505];

bool cmp(node a, node b) {
	return a.nx < b.nx;
}

void fac() {
	for (int i = 1; i <= n; i++) {

		if (ms[i] == 0) {
			a++;
		}
	}

}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.in", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> ms[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k[i].nx;
		k[i].bh = i;
	}

	for (int i = n; i > 1; i--) {

		sum *= i;
	}

	cout << sum % 998244353;
	return 0;
}