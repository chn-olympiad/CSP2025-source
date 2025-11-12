#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],sum,x,xx,yy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	sum=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m/2;i++)
	{
		if(i!=n*m-i+1)
		{
			swap(a[i],a[n*m-i+1]);
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(sum==a[i])
		{
			x=i;
			break;
		}
	}
	if(x%n>0)
	{
		xx++;
	}
	xx=xx+x/n;
	if(xx%2==1)
	{
		yy=(x-1)%m+1;
	}
	else
	{
		yy=m-((x-1)%m+1)+1;
	}
	printf("%d %d",xx,yy);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
