#include <bits/stdc++.h>
using namespace std;
int n, m, k, wz = 0, cz = 0, z = 0;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", n, m, k);
	int w[m], c[k];
	for (int i = 1; i <= m; i++) {
		scanf("%d", w);
		wz += w[i];
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", c);
		cz += c[k];
	}
	z = wz + cz;
	cout << cz;
	fclose(stdin);
	fclose(stdout);
	return 0;
}