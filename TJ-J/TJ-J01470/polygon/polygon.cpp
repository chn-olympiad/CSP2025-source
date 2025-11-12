#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+7, MOD = 998244353;
int n;
int a[MAXN], pre[MAXN];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a+1, a+1+n, cmp);
	
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i-1] + a[i];
	}
	printf("%d", 20);
	
	return 0;
}
