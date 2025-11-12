#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],R,x,y,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(R<=a[i])
		{
			t++;
		}
	}
	x=t/n+(t%n!=0);
	if(x%2)
	{
		y=(t-1)%n+1;
	}
	if(x%2==0)
	{
		y=n-(t-1)%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
