#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans,a[111];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[++ans]==x)
				{
					cout<<i<<' '<<j;
					break;
				}
			}
		}
		else
		{
			for(int j=n;j>0;j--)
			{
				if(a[++ans]==x)
				{
					cout<<i<<' '<<j;
					break;
				}
			}
		}
	}
	return 0;
}

