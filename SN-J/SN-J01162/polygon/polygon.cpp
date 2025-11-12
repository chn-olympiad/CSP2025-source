#include <bits/stdc++.h>
using namespace std;
const int S = 998244353;
int k[5005];
int n;
int s = 0;
int f(int l, int r, int k[]) {
	long long n = 0;
	for (int i = l; i <= r ; i++) {
		n += k[i];
	}
	return n;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	for (int m = 3; m <= n; m++) {
		for (int i = 0; i <= n - m; i++) {
			for (int j = i + m - 1; j < n; j++) {
				long long p = f(i, j, k);
				if (p > k[j] * 2) {
					s++;
				}
			}
		}
	}
	cout << s % S;
	return 0;
}
