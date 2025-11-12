#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k,m,n,a[105]={0},x,max=0;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			if(a[i]>a[1]) max+=1;
		}
	}
	x=max+1;
	if(x%n==0)
	{
		if(x/n%2==1)
		{
			cout<<x/n<<" "<<n;
		}
		else
		{
			cout<<x/n<<" "<<1;
		}
	}
	else if(x%n<=n/2)
	{
		if((x/n+1)%2==1)
		{
			cout<<x/n+1<<" "<<x%n;
		}
		else
		{
			cout<<x/n+1<<" "<<n-(x%n)+1;
		}
	}
	else
	{
		if(x/n%2==1)
		{
			cout<<x/n<<" "<<x%n;
		}
		else
		{
			cout<<x/n<<" "<<n-(x%n);
		}
	}
	return 0;
}
