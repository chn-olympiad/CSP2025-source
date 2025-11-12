#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6+10;
int t, sum, numa, numb, mid, mmax;
int a1[maxn], a2[maxn], a3[maxn], de[maxn];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		mid = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]) ;
		}
		for (int i = 1; i <= n; i++) {
			if (a2[i] == 0 && a3[i] == 0) {
				numa++;
			} else if (a3[i] == 0) {
				numb++;
			}
		}
		if (n == 2) {
			sum = max(a1[1] + a1[2], a1[1] + a2[2]);
			sum = max(sum, a1[1] + a3[2]);
			sum = max(sum, a2[1] + a2[2]);
			sum = max(sum, a2[1] + a3[2]);
			sum = max(sum, a3[1] + a3[2]);
			printf("%d\n", sum);
			sum = 0;
		}  else {
			if (numa == n) {
				sort(a2 + 1, a2 + n + 1);
				for (int i = n; i >= mid; i--) {
					sum += a2[i];
				}
				printf("%d\n", sum);
				sum = 0;
			} else {
				for (int i = 1; i <= n; i++) {
					mmax = max(a1[i], a2[i]);
					mmax = max(mmax, a3[i]);
					sum += mmax;
					mmax = 0;
				}
				cout << mmax << endl;
			}
		}
	}
	
	return 0;
}
