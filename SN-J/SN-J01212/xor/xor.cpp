//SN-J01212 Æë¾ýºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;
const int M = 4000010;

int n, k, a[N], s[N], ls[N];
int f[N][2];
int num[M];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	for(int i = 0; i <= M - 10; i++)
		num[i] = -1, ls[i] = -1;
	num[0] = 0;
	for(int i = 1; i <= n; i++) {
		int x = s[i] ^ k;
	 	if(num[x] != -1)
			ls[i] = num[x] + 1;
		num[s[i]] = i;
	}
	for(int i = 0; i <= n; i++)
		f[i][0] = f[i][1] = 0;
	for(int i = 1; i <= n; i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		if(ls[i] != -1)
			f[i][1] = f[ls[i]][0] + 1; 
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, max(f[i][0], f[i][1]));
	printf("%d\n", ans);
	return 0;
}
