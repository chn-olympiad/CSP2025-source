#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5010, Mod = 998244353;

int n;
int a[N], s[N], f[N], ans, bp = 1;

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	f[0] = s[0] = 1;
	for(int i = 1; i <= 5000; i ++) s[i] ++;
	for(int i = 1; i <= n; i ++){
		(ans += ((bp - s[a[i]]) % Mod + Mod) % Mod) %= Mod;
		(bp <<= 1) %= Mod;
		for(int j = 5000; j >= a[i]; j --){
			(f[j] += f[j - a[i]]) %= Mod;
		}
		for(int j = 1; j <= 5000; j ++) s[j] = (s[j - 1] + f[j]) % Mod;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
-------------------------hty111-------------------------
T4: 计数类 dp
将题目中的条件转化为：
除最大边外所有边的和**严格大于**最大边。

我们发现，最大边不好枚举。
因此，我们给原数组排个序，那么当前枚举到的就是最大边。

现在问题只剩下了求大于最大边的和有多少个。
发现如果暴力 dp，时间复杂度 $\mathcal O(n^3)$会爆掉。

因此，我们考虑反着来：
求和小于等于当前边的数目。
那么统计时，就用总方案数减去 dp 值，就是我们要求的合法数。

时间复杂度: $\mathcal O(n^2)$。

Expect: 100pts

对拍：50000 with O(2^n)[暴力]
-------------------------hty111-------------------------
*/