#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i],a[i]=-a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1,dx=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		x+=dx;
		if(x>n)
		{
			x=n;
			y++;
			dx=-1;
		}
		else if(x<1)
		{
			x=1;
			y++;
			dx=1;
		}
	}
	return 0;
}
