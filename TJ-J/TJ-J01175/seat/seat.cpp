#include <bits/stdc++.h>

using namespace std;

int a[101];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,seat;
	cin >>n>>m;
	int nm=n*m;
	for (int i=1;i<=nm;i++)
	{
		cin >>a[i];
	}
	int r=a[1];
	sort (a+1,a+nm+1);
	int b=0;
	for (int i=1;i<=n;i++)
	{
		if (i%2==0)
		{
			for (int j=m;j>=1;j--)
			{
				b++;
				if (a[b]==r)
				{
					cout <<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for (int j=1;j<=m;j++)
			{
				b++;
				if (a[b]==r)
				{
					cout <<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
 } 
