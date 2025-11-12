#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010];
long long ans = 0;

int main() {
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf ("%d",&a[i]);
	}
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			for (int l = j + 1;l <= n;l++) {
				if (a[i] + a[j] + a[l] > max (max(a[i],a[j]),a[l]) * 2) {
					ans++;
				}
			}
		}
	}
	printf ("%lld\n",ans);
}
