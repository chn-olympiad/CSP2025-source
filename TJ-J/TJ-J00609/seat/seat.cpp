#include <bits/stdc++.h>
using namespace std;

int a[15][15],b[1005];

int cmp(int a,int b)
{
	return a >b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cur=1;
	for(int i=1;i<=n*m;i++)
	{
		cin >> b[i];
	}
	int tot=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				a[j][i]=b[cur];
				cur++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				a[j][i]=b[cur];
				cur++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) 
	{
		if(a[i][j]==tot)
		{
			cout << j%998244353 << " " << i%998244353;
			return 0;
		}
	}
	return 0;
}
