#include <bits/stdc++.h>
using namespace std;
int n, sum, c, m;
int a[100010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		//int m = a[1];
		m = max(a[i], m);
	}

	for (int i = 1; i <= n ; i++) {
		for (int j = 3; j <= n; j++) {
			sum = sum + a[i];
			if (sum > m * 2) {
				c++;
			}
		}

	}
	//cout << m * 2;
	cout << c % 998244353;

}


