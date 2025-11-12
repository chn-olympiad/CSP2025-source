#include <bits/stdc++.h>
using namespace std;
long long a[500050];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	long long k, mut = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			long long cnt = 0;
			for (int o = i; o <= j; o++) {
				cnt = (cnt ^a[o]);
			}
			if (cnt == k) {
				mut++;
				i = j + 1;
			}
		}
	}
	cout << mut;
	return 0;

}
