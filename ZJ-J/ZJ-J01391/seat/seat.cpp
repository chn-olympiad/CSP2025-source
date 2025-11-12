#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[105];
int main()
{
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1],sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			x=n*m-i+1;
			break;
		}
	}
	y=(x+n-1)/n,cout<<y<<' ';
	if(y%2)cout<<n+x-n*y;
	else cout<<n*y+1-x;
}
