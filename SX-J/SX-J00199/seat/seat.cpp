#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10][10],b[105];
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int x=b[0];
	sort(b,b+n+m);
	int t=n*m;
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
			{
				a[j][i]=b[t];
				t--;
			}
		}
		else
		{
			for(int j=n;j>0;j++)
			{
				a[j][i]=b[t];
				t--;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==x)
			{
				cout<<i<<" "<<j;
				break;
			}
		}
	}
}
