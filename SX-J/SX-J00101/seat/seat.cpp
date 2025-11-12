#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10010000],zuo[10010][10010];
int n,m,q;
int p=1;
cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	q=a[1];
	int w=n*m;
	sort(a+1,a+1+w,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				zuo[j][i]=a[p];
				p++;
			}
		}
		if(j%2==0)
		{
			for(int z=n;z>=1;z--)
			{
				zuo[j][z]=a[p];
				p++;
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
  		if(zuo[j][i]==q)
			{
				cout<<j<<" "<<i<<endl;
			}
		}
	}
	return 0;
}