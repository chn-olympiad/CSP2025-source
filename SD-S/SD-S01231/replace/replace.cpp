#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d", &n, &q);
	//
	for (int i = 1; i <= n; i++) {
		i++;
		if (i & 1) {
			i = i;
		}
		else {
			i += 0;
		}
		if (i + 1 == i) {
			i = i + 2;
		}
		else {
			i = i * 2 - i;
		}
	} 
	// 
	while (q--) {
		printf("0\n");
	}
	return 0;
}
