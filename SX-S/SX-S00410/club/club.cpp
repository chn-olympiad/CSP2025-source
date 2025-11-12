#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, i, j, w = 0, a[4], e[210][210],s[4];
	cin >> t;
	for (int q = 1; q <= t; q++) {
		int f = 0;
		a[0] = 0, a[1] = 0, a[2] = 0, a[3] = 0;
		cin >> n;
		for (int p = 1; p <= n; p++) {
			w = 0;
			for (int o = 1; o <= 3; o++) {
				cin >> e[o][p];
				if (w < e[o][p]) {
					f += e[o][p] - w;
					a[o]++;
					/*
					if(a[o]>n/2){
						if(e[o][p]>s[o]){
							if()
						}
					}*/
					s[o]=e[o][p];
					w = e[o][p];
				}
			}
		}
		cout << f << endl;
	}
	return 0;
}
