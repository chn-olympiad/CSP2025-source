#include <bits/stdc++.h>

using namespace std;

int t, n, numa, numb, numc;
long long a[100001], b[100001], c[100001], ans, f[100001];
bool ta, tb;

long long dfs(int p, long num, int numa, int numb, int numc){
	if (numa > (n / 2) || numb > (n / 2) || numc > (n /2))
		return -(1 << 30);
	if (p == n + 1){
		return 0;
	}
	long long ans1, ans2, ans3, ans;
	ans1 = dfs(p + 1, num + a[p], numa + 1, numb, numc);
	ans2 = dfs(p + 1, num + b[p], numa, numb + 1, numc);
	ans3 = dfs(p + 1, num + c[p], numa, numb, numc + 1);
	if (ans1 > ans2){
		if (ans1 > ans3)
			return ans1;
		else
			return ans3;
	}
	else{
		if (ans2 > ans3)
			return ans2;
		else
			return ans3;
	}
}

int main (){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++){
		ans = 0;
		scanf ("%d", &n);
		ta = true;
		tb = true;
		for (int j = 1; j <= n; j++){
			scanf("%d%d%d", &a[j], &b[j], &c[j]);
			if (b[j] != 0 || c[j] != 0)
				ta = false;
			if (c[j] != 0)
				tb = false;
		} 
		if (ta){
			sort(a + 1, a + n + 1);
			for (int j = n; j > (n / 2); j--)
				ans += a[j];
			printf ("%lld\n", ans);
			continue;
		}
		if (tb && !ta){
			memset(f, 128, sizeof(f));
			f[0] = b[1];
			for (int k = 1; k <= n; k++){
				for (int j = n / 2; j >= 0; j--){
					if (k == 1){
						f[1] = a[k];
						continue;
					}
					else
						f[j] = max (f[j] + b[k], f[j - 1] + a[k]); 
				}
			//	for (int j = 0; j <= n / 2; j++)
			//		printf ("%d ", f[j + 1]);
			//	printf ("\n");
			}
			printf ("%d\n", f[n / 2]);
			continue;
		}
		else{
			printf ("%lld\n", dfs(1, 0, 0, 0, 0));
		}
	}
	return 0;
} 
