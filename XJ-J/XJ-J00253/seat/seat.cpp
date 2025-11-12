#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m,a[15][15],b[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
    }
    int p=b[1];
	int y=m*n;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(b[i]>b[j])
			{
				int t=b[j];
				b[j]=b[i];
				b[i]=t;
			}
		}
	}
	int o=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[o];
				o++;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[o];
				o++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(a[i][j]==p)
				{
					cout<<i<<" "<<j;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]==p)
				{
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
 } 
