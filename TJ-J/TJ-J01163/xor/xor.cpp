#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005];
long long sum = 0;
int x[500005];
int ii = 1;
bool aaa(int a, int b)
{
	for(int i = 1; i <= ii; i++)
	{
		if(a <= x[i] && b >= x[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == k)
		{
			sum++;
			x[ii] = i;
			ii++;
		}
	}
	int j1 = 0;
	for(int i = 1; i < n; i++)
	{
		int ans = a[i];
		for(int j = i + 1; j <= n; j++)
		{
			ans = ans ^ a[j];
			if(ans == k && aaa(i, j) == true && i > j1)
			{
				j1 = j;
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
