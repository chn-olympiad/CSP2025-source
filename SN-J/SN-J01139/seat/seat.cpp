#include<bits/stdc++.h>
using namespace std;
int n,m,c[100],a[15][15],ant = 1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++)
	{
		cin >> c[i];
	}
	for(int i = 1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j = n;j>=1;j--)
			{
				a[j][i] = ant;
				ant++;
			}
		}
		else
		{
			for(int j = 1;j<=n;j++)
			{
				a[j][i] = ant;
				ant++;
			}
		}
	}
	ant = c[1];
	sort(c+1,c+1+n*m);
	int ans = 1;
	for(int i = n*m;i>=1;i--)
	{
		if(c[i]==ant)
		{
			ant = ans;
		}
		ans++;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(ant==a[i][j])
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
