#include<bits/stdc++.h>
using namespace std;
int n,m,b[150],a[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	   cin>>b[i];
	int x=b[1],t=n*m;
	sort(b+1,b+n*m+1);
	if(x==b[1]) 
	{
		cout<<m<<" "<<n;
		return 0;
	}
	else if(x==b[n*m])
	{
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[t];
				t--;
				if(a[i][j]==x) 
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else 
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[t];
				t--;
				if(a[i][j]==x) 
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
