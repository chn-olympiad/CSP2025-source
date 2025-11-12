#include<bits/stdc++.h>
using namespace std;

int a[105];
int b[15][15];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	int r;
	for(int i = 1;i <= n * m;i++)
	{
		if(i == 1)
		{
			cin >> r;
			a[1] = r;
		}
		else
		{
			cin >> a[i];
		}
	}
	sort(a + 1,a + n * m + 1,cmp);
	int x = 1,y = 0;
	for(int i = 1;i <= n * m;i++)
	{
		if(x % 2 == 1)
		{
			if(y < n)
			{
				y++;
			}
			else
			{
				x++;
			}
		}
		else
		{
			if(y > 1)
			{
				y--;
			}
			else
			{
				x++;
			}
		}
		b[x][y] = a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(b[i][j] == r)
			{
				cout << i << ' ' << j;
				break;
			}
		}
	}
	return 0;
}