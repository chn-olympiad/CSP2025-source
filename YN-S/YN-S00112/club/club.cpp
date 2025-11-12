#include <bits/stdc++.h>
using namespace std;
int n, t;
int a1, a2, a3, ma;

int main() {
	scanf("%d", &t);
	for (int j = 1; j <= t; j++) {
		scanf("%d", &n);
		int b1 = 0, b2 = 0, b3 = 0, ma1 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1, &a2, &a3);
			ma = max(a1, max(a2, a3));
			ma1 += ma;
			if (ma == a1)
				b1++;
			else {
				if (ma == a2)
					b2++;
				else
					b3++;
			}
		}
		printf("%d\n", ma1);
	}
	return 0;


}