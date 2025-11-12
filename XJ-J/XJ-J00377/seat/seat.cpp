#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],c;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		c=a[1];
	}
	sort(a+n*m+1,a+1);
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i+j-1]==c)
				{
					cout<<i<<' '<<j;
					break;
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i+j-1]==c)
				{
					cout<<i<<' '<<j;
					break;
				}
			}
		}
	}
	return 0;
 } 
