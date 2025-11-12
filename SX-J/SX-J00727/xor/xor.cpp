#include <bits/stdc++.h>
using namespace std;
long long n, kl, I = 0;
long long a[10010];

long long con(long long af, long long bf) {
	long long ad[300] = {}, bd[300] = {}, aI = 0, bI = 0, jg[300], tjg = 0;
	while (af != 0) {
		ad[++aI] = af % 2;
		af /= 2;
	}
	while (bf != 0) {
		bd[++bI] = bf % 2;
		bf /= 2;
	}
	for (int i = 1; i <= max(aI, bI); i++) {
		jg[i] = abs(ad[i] - bd[i]);
	}
	long long rt = 1;
	for (int i = 1; i <= max(aI, bI); i++) {
		tjg += jg[i] * rt;
		rt *= 2;
	}
	return tjg;
}

void find(long long left, long long right) {
	for (int j = left; j <= right; j++) {
		for (int i = left; i <= j; i++) {
			long long s = a[i];
			for (int k = i; k < j; k++) {
				s = con(s, a[k + 1]);
			}
			if (s == kl) {
				I++;
				find(j + 1, right);
				return;
			}
		}
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> kl;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	find(1, n);
	cout << I;
	return 0;
}
