#include <bits/stdc++.h>

using namespace std;

int n, a[1003], x[1003][1003], k, f[1003];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		x[i][i] = a[i];
		for(int j = i+1; j <= n; j++) {
			x[i][j] = x[i][j-1] ^ a[j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(x[j][i] == k) f[i] = max(f[i], f[j-1]+1);
		}
	}
	cout << f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

