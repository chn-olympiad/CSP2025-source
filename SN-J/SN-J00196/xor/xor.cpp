//考号：SN-J00196 姓名：吴泽铭 学校：白水县城关第一初级中学 
#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,m;
	cout << n << m;
	int a[n];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int l= 1,r= n,maxx = -1;
	int mid = l,p,q;
	for (int i = 0;i <= n;++i)
	{
		if (l == mid)
		{
			p = l;
			q = a[mid+1];
			for (int i = mid+1;i <= r++i)
			{
				q = q^a[i+1];
			}
		}
		else if (mid == r)
		{
			q = r;
			for (int i = l;i <= mid-1;++i)
			{
				
			}
		}
		else
		{
			for (int i =l;i <= mid;++i)
			{
				
			}
			for (int i = mid+1;i <= r++i)
			{
				q = q^a[i+1];
			}
		}
		maxx = max(p,q);
	}
	cout << maxx;
	return 0;
}
