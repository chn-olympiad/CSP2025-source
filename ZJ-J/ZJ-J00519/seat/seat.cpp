/*
把long long换成long long
开freopen
去#define 
*/
#include <bits/stdc++.h>
using namespace std;
long long n,m;
struct NODE
{
	long long x,y;
	bool operator <(const NODE t) const
	{
		return x>t.x;
	}
} a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
    	cin>>a[i].x;
    	a[i].y = i;
	}
	sort(a+1,a+1+n*m);
	long long x = 0;
	long long y = 1;
	long long f = 1;
	for(long long i=1;i<=n*m;i++)
	{
		x += f;
		if(x>n)
		{
			y++;
			x = n;
			f = -1;
		}
		if(x<1)
		{
			y++;
			x = 1;
			f = 1;
		}
		if(a[i].y==1)
		{
			cout<<y<<" "<<x;
			break;
		}
	}
    return 0;
}

