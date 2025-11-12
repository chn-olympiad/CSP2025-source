#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[100001][4];
long long dp[501][501][501];
long long f(long long k = 1,long long ak = 0,long long bk = 0)
{
	if(ak > n / 2 || bk > n / 2 || k - 1 - ak - bk > n / 2)
	{
		return -2e9;
	}
	if(k > n)
	{
		return 0;
	}
	if(!dp[k][ak][bk])
	{
		long long res1 = f(k + 1,ak + 1,bk) + a[k][1];
		long long res2 = f(k + 1,ak,bk + 1) + a[k][2];
		long long res3 = f(k + 1,ak,bk) + a[k][3];
		dp[k][ak][bk] = max(res1,max(res2,res3));
	}
	return dp[k][ak][bk];
}

int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin >> t;
	for(long long q = 1;q <= t;q++)
	{
		cin >> n;
		memset(dp,0,sizeof(dp));
		for(long long i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		cout << f() << endl;
	}
	return 0;
}
