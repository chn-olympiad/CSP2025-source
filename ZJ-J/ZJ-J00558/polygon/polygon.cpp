#include <bits/stdc++.h>
using namespace std;

const int N = 5010, MOD = 998244353;
int n;
int a[N];
int find(int m);
int pick(int l, int n, int m);
int find(int m)
{
	int d = 0;
	for(int a = m - 1; a >= 3; a ++)
	{
	    d += pick(1, a, m);	
	} 
	return d;
}
int pick(int l, int n, int m)
{
	int ans = 0;
	for(int i = l; i <= n; i ++)
	{
		a[i] += pick(i + 1, n - 1, m);
		if(a[i] >= m)ans ++;
		a[i] -= pick(i + 1, n - 1, m);
	}
	return ans;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int num = 0, maxv = 0;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		num += a[i];
	}
	sort(a + 1, a + n + 1);
	while(a[n] * 2  >= num)
	{
		num -= a[n];
		a[n] = 0;
		n --;
	}
	int cnt = 1;
	for(int m = n - 1; m >= 1; m --)
	{
		cnt += find(m);
	}
	printf("%d", cnt % MOD);
	return 0;	
}
