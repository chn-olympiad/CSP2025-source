#include <bits/stdc++.h>
using namespace std;

long long n, k;
int a[500000];
int dp[500000];	//dp[i] 表示从i开始，最短的区间。若没有就是-1。 
// 思路，先由a数组得到DP数组，再求出DP数组的最长且不相交的子序列的长度。

// 求出DP数组的最长且不相交的子序列的长度 
int f(int arr[], int length)
{
	int max_ = 0;
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] == -1) continue;
		int len = 1;
		for (int j = arr[i] + 1; j < length; ++j)
		{
			if (arr[j] == -1) continue;
			++len;
			j = arr[j] + 1;
		}
		max_ = max(max_, len);
	}
	
	return max_;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n; ++i)
	{
		int ans = 0;
		for (int p = 0; p < n - i; ++p)
		{
			ans ^= a[i + p];
			if (ans == k)
			{
				dp[i] = i + p;
				goto B;
			}
		}
		dp[i] = -1;
		B:
		continue;
	}
	
//	for (int i = 0; i < n; ++i)
//	{
//		cout << dp[i] << endl;
//	}
	
	cout << f(dp, n) << endl;
	
	return 0;
 } 
