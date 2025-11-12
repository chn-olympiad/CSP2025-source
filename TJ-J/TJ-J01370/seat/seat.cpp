#include<bits/stdc++.h>
using namespace std;
int n,m,x,d;
int c[110]={0},a[110]={0};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	x=n*m;
	for(int i=1;i<=x;i++)
	{
		scanf("%d",&c[i]);
	}
	int z=c[1];
	sort(c+1,c+x+1);
	for(int i=1;i<=x;i++)
	{
		a[i]=c[x-i+1];
	}
	int f=0;
	for(int i=1;i<=x;i++)
	{
		if(a[i]==z)
		{
			f=i;
		}
	}
	int i=1;
	for(;f>n;i++)
	{
		f-=n;
	}
	if(i%2==1)
	printf("%d %d",i,f);
	else
	{
		printf("%d %d",i,n-f+1);
	}
	return 0;
}
