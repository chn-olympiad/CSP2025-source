#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,f,ansn,ansm;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=m*n;i>=1;i--)
	{
		if(a[i]==x)
		{
			f=m*n-i+1;
			break;
		}
	}
	if(f%(2*n)>n)
	{
		ansm=f/n+int(bool(f%n));
		ansn=(2*n)-f%(2*n)+1;
	}
	else if(f%(2*n)<=n)
	{
		ansm=f/n+int(bool(f%n));
		ansn=f%(2*n);
	}
	cout<<ansm<<" "<<ansn;
	return 0;
}
