#include <bits/stdc++.h>
using namespace std;
long long n,m,s[10010],a;
int comp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&s[i]);
	}
	a=s[1];
	sort(s+1,s+n*m+1,comp);
	long long sum=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[sum]==a)
				{
					printf("%d %d",i,j);
					return 0;
				}
				sum++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(s[sum]==a)
				{
					printf("%d %d",i,j);
					return 0;
				}
				sum++;
			}
		}
	}
	return 0;
}