#include<bits/stdc++.h>
using namespace std;
long long int a[105],i,zs,n,m,R,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zs=n*m;
	for(i=1;i<=zs;i++)
	cin>>a[i];
	R=a[1];
	sort(a+1,a+1+zs,greater<int>());
	if(n==1)
	for(i=1;i<=zs;i++)
	if(a[i]==R)
	{
		cout<<i<<" "<<"1";
		return 0;
	}
	for(i=1;i<=zs;i++)
	if(a[i]==R)
	{
		if(i==n)
		c=i/n;
		else
		c=i/n+1;
		if(c%2==0)
		r=n-i+(c-1)*n+1;
		else
		r=i-(c-1)*n;
	}
	cout<<c<<" "<<r;
	return 0;
}
