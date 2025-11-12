#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,f,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i])
		{
			f=n*m-i+1;
			break;
		}
	}
	if(f%n==0)	
	{
		y=f/n;
		if(y%2==0) x=1;
		else x=n;
	}
	else 
	{
		y=f/n+1;
		if(y%2==0) x=n-(f-(y-1)*n)+1;
		else x=f-(y-1)*n;
	}
	printf("%d %d",y,x);
	return 0;
}
