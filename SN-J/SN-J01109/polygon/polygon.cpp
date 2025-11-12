#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	vector <int> a(1000,0); 
	int n,m,c = 0;
	cin >> n >> m;
	c = n*m;
	cin >> a[0];
	int r = a[0];
	for(int i = 1;i <= c - 1;i++)
	{
		cin >> a[i];
	}
	int j = 0;
	for(int i = 1;i <= a.size();i++)
	{
		int b = a[j];
		if(a[i] > a[j])
		{
			a[j] = a[i];
			a[i] = b;
		}
	}
	int x = 0;
	for(int i = 0;i <= a.size();i++)
	{
		x++;
		if(a[i] == r)
		{
			break;
		}
	}
	int y = 0;
	int t = 0;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;i++)
		{
			y++;
			if(x == y)
			{
				cout << j << " "<< i;
				t++;
				break;
			}
		}
		i++;
		for(int j = n;j >= 1;i--)
		{
			y++;
			if(x == y)
			{
				cout << j << " "<< i;
				t++;
				break;
			}
		}
		if(t == 0)
		{
			break;
		}
	}
	
	return 0;
}
