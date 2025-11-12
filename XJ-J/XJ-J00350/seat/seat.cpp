#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,n,m,s=0,l,z,dx,dy;
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(l==a[i])
		{
			z=i;
			break;
		}
	}
	if(z%n==0)
	{
		dy=z/n;	
		if(dy%2==1)
		{
			dx=n;
		}
		else
		{
			dx=1;
		}
	}
	else
	{
		dy=z/n+1;
		if(dy%2==1)
		{
			dx=z%n;
		}
		else
		{
			dx=n-z%n+1;
		}
	}
	cout<<dy<<" "<<dx;
	return 0;
 } 
