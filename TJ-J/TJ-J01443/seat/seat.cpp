#include <bits/stdc++.h>
using namespace std;
int n,m,a[200],c,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			if(i%n!=0)
			{
				c=i/n+1;
				if(c%2==0)
				{
					r=m-i%n+1;
				}
				else
				{
					r=i%n;
				}
			}
			else
			{
				c=i/n;
				if(c%2==0)
					r=1;
				else
					r=m;
			}
			break;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
