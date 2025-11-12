//SN-J00645 杨陈泽 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
int n , m , a[150];
bool cmp(int x , int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n*m ; i++)
	{
		cin >> a[i];
	}
	int x = a[1];
	sort(a + 1 , a + n * m + 1 , cmp);
	for(int i = 1 ; i <= n*m ; i++)
	{
		if(a[i] == x)
		{
			x = i;
			break;
		}
	}
	if(x % n == 0)
	{
		int y = x / n;
		cout << y << " ";
		if(y % 2 == 0)
		{
			cout << 1;
		}
		else
		{
			cout << n;
		}
	}
	else
	{
		int y = x / n;
		x -= y * n;
		cout << y + 1 << " ";
		if(y % 2 == 0)
		{
			cout << x;
		}
		else
		{
			cout << n-x+1;
		}
	}
	return 0;
}

