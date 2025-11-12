#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=m*n;i;i--)
	{
		scanf("%d",&a[i]);
	}
	
	a[0]=a[n*m];
	sort(a+1,a+1+(m*n));
	for(int i=1,cnt=n*m;i<=m;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++,cnt--)
			{
				if(a[0]==a[cnt])
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j;j--,cnt--)
			{
				if(a[0]==a[cnt])
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
