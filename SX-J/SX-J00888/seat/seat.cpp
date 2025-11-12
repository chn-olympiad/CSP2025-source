#include <bits/stdc++.h>
using namespace std;
int b[110];
int a[15][15];

bool cmp1(int x, int y) {
	return x > y;
}

int main() {
	fropen("seat.in", "r", stdin);
	fropen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int v = m * n;
	for (int i = 1; i <= v; i++) {
		cin >> b[i];
	}
	int ar = b[1];
	int l = 0;
	sort(b + 1, b + v + 1, cmp1);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int o = 1; o <= n; o++) {
				l++;
				if (b[l] == ar) {
					printf("%d %d", i, o);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		} else {
			for (int o = n; o >= 1; o--) {
				l++;
				if (b[l] == ar) {
					printf("%d %d", i, o);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
