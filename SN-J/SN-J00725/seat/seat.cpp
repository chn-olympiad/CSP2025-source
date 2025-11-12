#include <bits/stdc++.h>
using namespace std;
int n,m,s,R,ans,b[105],c,r,sum = 0;
int main()
{
	freopen("sent.in","r",stdin);
	freopen("sent.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n * m;i++)
	{
		cin >> b[i];
	}
	R = b[0];
	for (int i = 0;i < n * m;i++)
	{
		for (int j = 0;j < n * m;j++)
		{	
			if(b[j] < b[j + 1])
			{
				s = b[j];
				b[j] = b[j + 1];
				b[j + 1] = s;
			}
		}
	}
	for (int i = 0;i < n * m;i++)
	{
		if (b[i] == R)
		{
			ans = i + 1;
		}
	}
	sum = ans / n;
	if(sum % 2 == 0)
	{
		if (ans % n == 0)
		{
			r = 1;
		}
		else
		{
			r = n - ans % n + 1;
		}
		if (ans % n  != 0)
		{
			c = sum + 1;
		}
		else
		{
			c = sum;
		}
	}
	else
	{
		if (ans % n == 0)
		{
			r = n;
		}
		else
		{
			r = ans % n;
		}
		if (ans % n  != 0)
		{
			c = sum + 1;
		}
		else
		{
			c = sum;
		}
	}
	cout << c << " " << r;
	return 0;
}
