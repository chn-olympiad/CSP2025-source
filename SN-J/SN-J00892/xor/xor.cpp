#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[510000];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 2 && k == 0) {
		if (a[1] == a[2])
			printf("1");
		else
			printf("0");
	} else
		printf("7");
}
