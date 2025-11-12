#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,k,x=0,y=0,flag;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];			
	}
	flag=a[1];
	sort(a+1,a+n*m+1);
	for(i=n*m;i>=1;i--)
	{
		if(a[i]==flag)
		{
			break;
		}
	}
	i=n*m-i;
	i++;
	x=1;
	for(j=1;j<=i;j++)
	{
		y++;
		if(y==n+1)
		{
			x++;
			y=y-n-1;
		}
		
	}
	if(x%2==0)
	{
		y=n-y;
	}
	cout<<x<<" "<<y;
	return 0;
}
