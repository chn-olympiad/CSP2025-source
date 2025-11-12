#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=1,y=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int a;
			cin>>a;
			if (i==1 && j==1)
			{
				ans=a;
				continue;
			}
			if(a>ans)
			{
				if (y%2==1)
				{
					if (x==n)y++;
					else x++;
				}
				else 
				{
					if (x==1)y++;
					else x--;
				}
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
