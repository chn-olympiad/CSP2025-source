#include<bits/stdc++.h>
using namespace std;
int a[10010];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,l,r,xr,wei=0;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+1+n*m,cmp);
	l=1;
	r=n*m;
	//cout<<xr;
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==xr)
		{
			wei=i;
			break;
		}
	}
	if(wei%n==0)
	{
		cout<<wei/n<<" ";
		if((wei/n)%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
	}
	else
	{
		cout<<wei/n+1<<" ";
		if((wei/n+1)%2==0)
		{
			cout<<n-wei%n+1;
		}
		else
		{
			cout<<wei%n;
		}
	}
	return 0;
}