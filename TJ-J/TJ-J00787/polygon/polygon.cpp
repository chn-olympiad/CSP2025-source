#include<bits/stdc++.h>

using namespace std;

int n, a[5010], g = 0;

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 3) {
		int d = a[1] + a[2] + a[3];
		int v = max(a[1], max(a[2], a[3])), r = d - v;
		if (v < r)
			g++; 
	}
	printf("%d", g);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
}
