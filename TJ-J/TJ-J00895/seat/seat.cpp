#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
bool cmp(int x , int y)
{
	
	return x > y;
}
int seat[15][15];
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++)
	{
		cin >> a[i];
	}
	int c = a[1];
	sort(a+1 , a+n*m+2 , cmp);
	
	int cnt = 1;
	for(int j = 1 ; j <= m ; j++)
	{
		if(j % 2 == 0)
		{
			for(int i = n ; i >= 1 ; i--)
			{
				seat[i][j] = a[cnt];
				cnt++;
			}
		}
		else
		{
			for(int i = 1 ; i <= n ; i++)
			{
				seat[i][j] = a[cnt];
				cnt++;
			}
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(seat[i][j] == c)
			{
				cout << j  << ' '<< i;
				return 0;
			}
			
		}
		
	}
	cout << c;
	return 0;
}
