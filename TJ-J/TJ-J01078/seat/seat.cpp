#include <bits/stdc++.h>
using namespace std;
bool cmp(int c,int b)
{
	return c>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int s[121];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int a=s[1];
	sort(s+1,s+n*m+1,cmp);
	int x=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(s[x]==a)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				x++;
			}	
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(s[x]==a)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				x++;
			}
		}
	}
	return 0;
}
