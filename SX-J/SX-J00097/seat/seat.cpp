#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,c,r,g;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(k==a[i])
		{
			g=i;
			break;
		}
	}
	g=n*m-g+1;
	if(g%n==0)
	{
		c=g/n;
		if(c%2==0)
		{
			r=1;
		}
		else r=n;
	}
	else
	{
		c=g/n+1;
		if(c%2==0)
		{
			r=n-g%n+1;
		}
		else r=g%n;
	}
	cout<<c<<" "<<r;
	return 0;
}