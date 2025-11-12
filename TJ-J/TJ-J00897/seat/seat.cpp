#include<bits/stdc++.h>
using namespace std;
int a[999][999],b[999];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n*m;i++)
	{
		scanf("%d",&b[i]);
	}
	int r = b[1];
	sort(b+1,b+1+n);
	int k = n;
	for(int i = n;i >= 1;i --)
	{
		if(i % 2==0)
		{
			for (int j = 1;j<= m;j++)
			{
				a[i][j] = b[k];
				k--;
			}
		}
		else
		{
			for (int j = m ;j >= 1;j --)
			{
				a[i][j] = b[k];
				k--;
			}
		}
	}
	for (int i = 1; i<=n;i ++)
	{
		for (int j = 1; j <= m;j ++)
		{
			if(a[i][j] == r)
			{
				printf("%d%c%d",i,' ',j);
				break;
			}
		}
	}
	return 0;
}
