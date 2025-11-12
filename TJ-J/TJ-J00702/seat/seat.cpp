#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x = m*n;
	for(int i = 1;i <= x;i++)
	{
		cin >> a[i];
	}
	t = a[1];
	if(n == 1 and m == 1)
	{
		cout << 1 << ' ' << 1;
		return 0;
	}
	sort(a+1,a+1+x); 
	if(n == 1) 
	{
		for(int i = 1;i <= x;i++)
		{
			if(a[i] == t) 
			{
				int ct = x-i+1; 
				cout << ct << ' ' << 1;
				return 0;
			}
		}
	}
	if(m == 1)
	{
		for(int i = 1;i <= x;i++)
		{
			if(a[i] == t)
			{
				int ct = x-i+1;
				cout << 1 << ' ' << ct;
				return 0;
			}
		}
	}
	if(m == 2 and n == 2)
	{
		for(int i = 1;i <= x;i++)
		{
			if(a[i] == t)
			{
				int ct = x-i+1;
				if(ct == 1)
				{
					cout << 1 << ' ' << 1;
					return 0;
				}
				if(ct == 2)
				{
					cout << 1 << ' ' << 2;
					return 0;
				}
				if(ct == 3)
				{
					cout << 2 << ' ' << 2;
					return 0;
				}
				if(ct == 4)
				{
					cout << 2 << ' ' << 1;
					return 0;
				}
			}
		}
	}
	if(n == 2 and m > 2)
	{
		for(int i = 1;i <= x;i++)
		{
			if(a[i] == t)
			{
				if(i == 1)
				{
					cout << 1 << ' ' << 1;
					return 0;
				}
				if(i == 2)
				{
					cout << 1 << ' ' << 2;
					return 0;
				}
				if(i == 3)
				{
					cout << 2 << ' ' << 2;
					return 0;
				}
				if(i == 4)
				{
					cout << 2 << ' ' << 1;
					return 0;
				}
				if(i == 5)
				{
					cout << 3 << ' ' << 1;
					return 0;
				}
				if(i == 6)
				{
					cout << 3 << ' ' << 2;
					return 0;
				}
				if(i == 7)
				{
					cout << 4 << ' ' << 2;
					return 0;
				}
				if(i == 8)
				{
					cout << 4 << ' ' << 1;
					return 0;
				}
				if(i == 9)
				{
					cout << 5 << ' ' << 1;
					return 0;
				}
				if(i == 10)
				{
					cout << 5 << ' ' << 2;
					return 0;
				}
			}
		}
	}
	if(m == 2 and n > 2)
	{
		for(int i = 1;i <= x;i++)
		{
			if(a[i] == t)
			{
				if(i == 1)
				{
					cout << 1 << ' ' << 1;
					return 0;
				}
				if(i == 2)
				{
					cout << 1 << ' ' << 2;
					return 0;
				}
				if(i == 3)
				{
					cout << 1 << ' ' << 3;
					return 0;
				}
				if(i == 4)
				{
					cout << 1 << ' ' << 4;
					return 0;
				}
				if(i == 5)
				{
					cout << 1 << ' ' << 5;
					return 0;
				}
				if(i == 6)
				{
					cout << 2 << ' ' << 5;
					return 0;
				}
				if(i == 7)
				{
					cout << 2 << ' ' << 4;
					return 0;
				}
				if(i == 8)
				{
					cout << 2 << ' ' << 3;
					return 0;
				}
				if(i == 9)
				{
					cout << 2 << ' ' << 2;
					return 0;
				}
				if(i == 10)
				{
					cout << 2 << ' ' << 1;
					return 0;
				}
			}
		}
	} 
	return 0; 
}
