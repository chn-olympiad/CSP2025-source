#include<bits/stdc++.h>
using namespace std;
int n,m,a[107],k;
int main()
{
//	system("fc seat3.ans seat.out");
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m,x=1,y=1,f=0;i>=1;i--)
	{
		if(k==a[i])
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if(f==0) y++;
		if(f==1) y--;
		if(y==n+1)
		{
			y=n;
			x++;
			f=1;
		}
		if(y==0)
		{
			y=1;
			x++;
			f=0;
		}
	}
	return 0;
}