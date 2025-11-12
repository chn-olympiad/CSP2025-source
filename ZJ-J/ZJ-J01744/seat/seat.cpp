#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],x,y,k,sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>k)
		{
			sum++;
		}
	}
	sum++;
	x=sum/n;
	y=sum-x*n;
	if(x%2==1)
	{
		y=m-y+1;
	}
	if(sum-x*n)
	{
		x++;
	}
	else
	{
		if(x%2==1)
		{
			y=m;
		}
		else
		{
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
