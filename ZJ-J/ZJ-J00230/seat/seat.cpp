#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,a[105],x=1,y=1,m,p;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1];
	p=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==p)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==1)
		{
			if(y==n)
			{
				x++;
			}
			else
			{
			y++;
		}
		}
		else
		{
			if(y==1)
			{
				x++;
			}
			else
			{
			y--;
			}
		}
	}
}

