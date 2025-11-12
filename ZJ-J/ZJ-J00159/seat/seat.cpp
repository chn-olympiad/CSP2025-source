#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int g=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int x=0,y=1,dir=0;
	for(int i=1;i<=n*m;i++)
	{
		if(dir == 0)
		{
			x++;
			if(x == n+1)
			{
				x=n;
				y++;
				dir=1;
			}
		}
		else
		{
			x--;
			if(x == 0)
			{
				x=1;
				y++;
				dir=0;
			}
		}
		if(a[i] == g)
		{
			cout<<y<<' '<<x;
			break;
		}
	}
	return 0;
}