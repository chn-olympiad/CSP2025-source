#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,val,t,pos=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		if(i==1)
		{
			scanf("%d",&val);
		}
		else
		{
			scanf("%d",&t);
			if(val<t)	pos++;
		}
	}
	t=pos/n+1;
	if(t%2==1)
	{
		printf("%d %d",pos/n+1,pos%n+1);
	}
	else
	{
		printf("%d %d",pos/n+1,n-pos%n);
	}
	return 0;
}
