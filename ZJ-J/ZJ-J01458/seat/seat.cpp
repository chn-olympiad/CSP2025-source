#include<bits/stdc++.h>
using namespace std;
int n,m,w,a[110],x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	w=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])w++;
	}
	x=(w+n-1)/n;
	y=w%n;
	if(y==0)y=n;
	if(x%2==1)y=n-y+1;
	cout<<x<<" "<<y;
}
