#include <bits/stdc++.h>
using namespace std;

int n,a[5005],res;
int sum_lr(int l, int r)
{
	int sum = 0;
	for (int i=l; i<=r; i++)
	{
		sum += a[i];
	}
	return sum;
}
int max_lr(int l, int r)
{
	int max_a = -1;
	for (int i=l; i<=r; i++)
	{
		max_a = max(a[i], max_a);
	}
	return max_a;
}

int sss(int l1, int l2, int l3)
{
	if (a[l1] + a[l2] > a[l3] && a[l1] + a[l3] > a[l2] && a[l2] + a[l3] > a[l1])
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i]; 
	}
	if (n <= 3)
	{
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
		{
			cout<<1;
			return 0;
		}
	}
	
	if (n == 4)
	{
		if ((a[1]+a[2]+a[3]+a[4]) > 2 * max(max(a[1], a[2]), max(a[3], a[4])))
		{
			res++;
		}
		if (sss(1,2,3))
		{
			res++;
		}
		if (sss(1,2,4))
		{
			res++;
		}
		if (sss(1,3,4))
		{
			res++;
		}
		if (sss(2,3,4))
		{
			res++;
		}
		cout<<res;
		return 0;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j++)
		{
			if (sum_lr(i,j) > (2 * max_lr(i,j)))
			{
				res++;
			}
			
		}
	}
	cout<<res+2 % 998244353;
}
	
