#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, M = 2e6 + 6;

int c[M], a[N], n, k, ans, s, la = 0;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	memset(c, -1, sizeof c);
	c[0] = 0;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		s ^= a[i];
		if(c[s ^ k] + 1 > la){
			la = i;
			ans ++;
		}
		c[s] = i;
	}
	printf("%d\n", ans);
	return 0;
}
/*
-------------------------hty111-------------------------
T3: 前缀和 + 贪心
满足题意的区间长度越短越好，越密越好。
数组 $c_i$ 表示前缀异或和为 $i$ 的下标最大的是多少
然后直接计算累计答案即可。

时间复杂度：$\mathcal O(n)$

Expect: 100pts

对拍：30000 (mine with O(n^2)[Dp]: 10000 ; mine with O(n)[Dp] : 20000)
-------------------------hty111-------------------------
*/