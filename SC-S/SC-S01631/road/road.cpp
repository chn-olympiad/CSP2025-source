#include <bits/stdc++.h>
using namespace std;

long long n, m, k, u[1000010], v[1000010], w[1000010], c[20], a[20][1000010];

int main (){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	for (int i = 1; i <= n; i++){
		scanf ("%lld%lld%lld", &u[i], &v[i], &w[i]);
	}
	int v = 1;
	for (int i = 1; i <= k; i++){
		scanf ("%lld", &c[i]);
		if (c[i] != 0)
			v = 0;
		for (int j = 1; j <= n; j++){
			scanf ("%lld", &a[i][j]);
			if (a[i][j] != 0)
				v = 0;
		}
	}
	if (v == 1)
		printf ("0");
	return 0;
}