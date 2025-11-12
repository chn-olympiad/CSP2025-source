#include <bits/stdc++.h>
using namespace std;
const int N=1000001,M=1001;
int n,m,a[N],r,x,y,t;
bool cmp (int x,int y)
{
	return x>y;
}
int main ()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	cin >>n>>m;
	for (int i=1;i<=n*m;i++) cin >>a[i];
	r=a[1];
	sort (a+1,a+1+n*m,cmp);
	x=y=1;t=1;
	while (r!=a[t])
	{
		if (y%2==1) x++;
		else x--;
		if (x==0) y++,x=1;
		if (x==n+1) y++,x=n;
		t++;
	}
	cout <<y<<" "<<x;
	return 0;
}
