#include <bits/stdc++.h>
using namespace std;
int n, m;
int k[15][15];
int f[105];
bool cmp(int a, int b) {
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> f[i];
	}
	int p = f[1];
	sort(f, f + s, cmp);
	int q = 0;
	for (int i = 1; i <= m; i++) {
		int l, j;
		if (i % 2 != 0) {
			l = 1; 
			j = 1;
		}
		else {
			l = -1;
			j = n;
		}
		for (j; j > 0 && j <= n; j += l) {
			k[j][i] = f[q];
			if (f[q] == p) {
				cout << i <<" " << j;
				break;
			}
			q++;
		}
	}
	return 0;
}
