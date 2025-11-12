#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500010;
const int MAXP = 2200000; 

int lastxor[MAXP], a[MAXN], xors[MAXN], ans[MAXN], n, k, ned;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	scanf("%d%d", &n, &k);
	xors[0] = 0;
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		xors[i] = xors[i-1] ^ a[i];
	}
	for (int i=0; i<MAXP; i++) {
		lastxor[i] = -1;
	}
	lastxor[0] = 0;

	ans[0] = 0;
	for (int i=1; i<=n; i++) {
		ans[i] = ans[i-1];
		ned = xors[i] ^ k;
		if (lastxor[ned] != -1) ans[i] = max(ans[i], ans[lastxor[ned]] + 1);
		lastxor[xors[i]] = i; 
	}
	printf("%d", ans[n]);
	return 0;
}
