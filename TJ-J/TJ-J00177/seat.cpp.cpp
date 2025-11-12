#include <iostream>
#include <algorithm>
using namespace std;

int a[1000];
int box[1000];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		box[a[i]]++;
	}
	int cnt = 0;
	for(int i = 100; i >= a[1]; i--)
	{
		cnt += box[i];
	}
	int x = 0;
	for (int i = 1; i <= m; i++)
	{
		if(i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				x++;
				if(x == cnt) 
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j = n; j >= 1; j--)
			{
				x++;
				if(x == cnt) 
				{
					cout << i << " " << j ;
					return 0;
				}
				
			}
		}
	}
	
}


