#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0,xl=0,yl=0,zl=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(n/2<=xl+1)
			{
				if(y>=z)
				{
					ans+=y;
					yl++;
				}
				else
				{
					ans+=z;
					zl++;
				}
			}
			else if(n/2<=yl+1)
			{
				if(y>z)
				{
					ans+=y;
					yl++;
				}
				else
				{
					ans+=z;
					zl++;
				}
			}
			else if(n/2<=zl+1)
			{
				if(x>y)
				{
					ans+=x;
					xl++;
				}
				else
				{
					ans+=y;
					yl++;
				}
			}
			else if(x>=y)
			{
				if(x>z)
				{
					ans+=x;
					xl++;
				}
				else
				{
					ans+=z;
					zl++;
				}
			}
			else
			{
				if(y>z)
				{
					ans+=y;
					yl++;
				}
				else
				{
					ans+=z;
					zl++;
				}
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
//3 4 4 2 1 3 2 4 5 3 4 3 5 1  4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0














