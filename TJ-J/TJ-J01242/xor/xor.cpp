#include <bits/stdc++.h>
using namespace std;

int n , k;
int a[500010];
long long t[500010];
bool tt[500010];
int ans = 0;

int main() {
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf ("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) {
		scanf ("%d",&a[i]);
	}
	t[0] = 0;
	t[1] = a[1];
	for (int i = 2;i <= n;i++) {
		t[i] = t[i - 1] ^ a[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			if (abs (t[j] - t[i - 1]) == k) {
				bool b = 1;
				for (int l = i;l <= j;l++) {
					if (tt[i] == 1) {
						b = 0;
					}
				}
				if (b) {
					ans++;
					for (int l = i;l <= j;l++) {
						tt[l] = 1;
					}				
				}
			}
		}
	}
	printf ("%d\n",ans);
}
