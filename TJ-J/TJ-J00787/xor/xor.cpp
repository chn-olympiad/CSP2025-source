#include<bits/stdc++.h>

using namespace std;

int n, g = 0;
long long k, a[500010];

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	long long x = 0;
	for (int i = 1; i <= n; i++) {
		x ^= a[i];
		if (x == k) {
			g++;
			x = 0;
		}
	}
	printf("%d", g);
	
	fclose(stdin);
	fclose(stdout);

	return 0; 
}
