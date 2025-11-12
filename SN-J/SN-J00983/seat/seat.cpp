#include<bits/stdc++.h>
using namespace std;
long long n,m,x=2;
long long a[101]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long sum=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n*m-1;j++)
	{
		if(a[1]>a[x])
			sum-=1;
		x++;
	}
	if(sum==1)
	{
		cout<<1<<' '<<1;
		return 0;	
	}
	if(sum==n*m)
	{
		cout<<n<<' '<<1;
		return 0;
	}
	if(sum/n==0)
	{
		cout<<1<<' '<<sum%n;
	}
	if(sum%n==0)
	{
		cout<<sum/n<<' '<<n; 
		return 0;
	}
	if(sum/n==1)
	{
		cout<<2<<' '<<sum%n;
	}
	if(sum/n==2)
	{
		cout<<3<<' '<<sum%n;
	}
	return 0;
} 
