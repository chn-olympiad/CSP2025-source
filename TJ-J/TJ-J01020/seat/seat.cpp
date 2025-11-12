#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n*m+5];
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int s=a[0];
	int l=1;
	for(int i=1;i<n*m;i++)
	{
		if(s<a[i])
		{
			l++;
		}
	}
	int x=0,y=0;
	if(l%n!=0)
	{
		y=l/n+1;
	}
	if(l%n==0)
	{
		y=l/n;
	}
	if(y%2==0)
	{
		x=n-(l%n)+1;
	}
	if(y%2!=0&&l%n==0)
	{
		x=n;
	}
	if(y%2!=0&&l%n!=0)
	{
		x=l%n;
	}
	printf("%d %d",y,x);
	fclose(stdin);
	fclose(stdout);
}
