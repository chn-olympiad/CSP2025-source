// 张洛川 高新第二初级中学 SN-J00375 
#include<bits/stdc++.h>
using namespace std;

const int N = 5005, MOD = 998244353;
int n;
int a[N];
long long ret = 0;

void dfs(int x, int len, int cnt, int l) {
	if (len == l) {
		for (int i = x; i <= n; i++) {
			if (cnt > a[i]) {
				ret++;
			}
		}
		return;
	}
	for (int i = x; i <= n; i++) {
		dfs(x+1, len+1, cnt+a[i], l);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	if (n == 3) {
		if (a[1]+a[2] > a[3]) {
			printf("1\n");
		} else {
			printf("0\n");
		}
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n-i+1; j++) {
			dfs(j, 1, 0, i);	
		}
	}
	printf("%lld\n", ret%MOD);
	return 0;
}
