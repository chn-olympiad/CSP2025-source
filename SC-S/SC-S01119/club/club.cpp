#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
long long t, z, z2;
struct A {
	long long i1, i2, i3;
} a[maxn];
long long solve(long long n) {
	long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
	z = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt1 <= n / 2) {
			if (a[i].i1 > a[i].i2 && a[i].i1 > a[i].i3) {
				z += a[i].i1;
				cnt1++;
				continue;
			}
			if (cnt2 <= n / 2) {
				if (a[i].i2 > a[i].i3) {
					z += a[i].i2;
					continue;
				}
				if (cnt3 <= n / 2) {
					z += a[i].i3;
					cnt3++;
					continue;
				}
			}
		}
	}
	return z;
}
void read() {
	memset(a, 0, sizeof(a));
	scanf("%lld", &t);
	for (int i = 1; i <= t; i++) {
		long long n;
		scanf("%lld", &n);
		for (int j = 1; j <= n; j++)scanf("%lld %lld %lld", &a[j].i1, &a[j].i2, &a[j].i3);
		if(n == 2){
			printf("%lld",max(max(max(a[1].i1 + a[2].i2,a[1].i1 + a[2].i3),max(a[2].i1 + a[1].i2,a[1].i2 + a[2].i2)),max(a[1].i3 + a[2].i1,a[1].i3 + a[2].i2)));
			return;
		}
		printf("%lld\n", solve(n));
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read();
	return 0;
}