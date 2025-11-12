#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,x;
int a[105],y;
int main()
{
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m,j=1;i>=1;i--,j++)
	{
		if(x==a[i])
		{
			y=j;
			break;
		}
	}
	int u=y/n;
	if(u*n<y) u++;
	cout<<u<<' ';
	int r=u*n-y;
	if(u%2==0) cout<<r+1;
	else cout<<n-r;
	return 0;
}
