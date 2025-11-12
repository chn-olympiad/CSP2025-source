#include<bits/stdc++.h>
using namespace std;
int n,m,num,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1,cnt=n*m;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[cnt]==num)
				{
					printf("%d %d",i,j);
					return 0;
				}
				cnt--;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[cnt]==num)
				{
					printf("%d %d",i,j);
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}