#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int seat[105];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r".stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> seat[i];
	}
	int r = seat[1];
	sort(seat + 1, seat + n * m + 1, cmp);
	bool b = true;
	int sum = 1;
	for(int i = 1; i <= m; i++)
	{
		if(b == true)
		{
			for(int j = 1; j <= n; j++)
			{
				a[j][i] = seat[sum];
				sum++;
			}
			b = false;
		}
		else
		{
			for(int j = n; j >= 1; j--)
			{
				a[j][i] = seat[sum];
				sum++;
			}
			b = true;
		}		
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == r)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
