#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1 << 20) + 11;
int n , k , a[500011] , cnt[N] , ans[500011], sm[500011];

int main () {
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf ("%d%d" , &n , &k);
	for (int i = 1;i <= n;i++) scanf ("%d" , &a[i]);
	for (int i = 0;i <= (1 << 20);i++) cnt[i] = n + 2;
	int sum = 0;
	cnt[0] = n + 1;
	for (int i = n;i >= 1;i--) {
		sum ^= a[i];
		ans[i] = cnt[sum ^ k] - 1;
		cnt[sum] = i;
	}
	sm[n + 1] = n + 1;
	for (int i = n;i >= 1;i--) sm[i] = min(sm[i + 1] , ans[i]);
	int x = 0 , res = 0;
	for (;;) {
		if (sm[x + 1] > n) break;
		x = sm[x + 1] , res++;	
	}
	printf ("%d\n" , res);
	return 0;
}