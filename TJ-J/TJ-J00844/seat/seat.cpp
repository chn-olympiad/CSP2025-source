#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],s[225],s1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=n*m;
	for(int i=1;i<=cnt;i++)
	{
		scanf("%d",&s[i]);
	}
	int ans=s[1];
	sort(s+1,s+cnt+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				s1++;
				a[i][j]=s[s1];
				if(s[s1]==ans)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				s1++;
				a[i][j]=s[s1];
				if(s[s1]==ans)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
