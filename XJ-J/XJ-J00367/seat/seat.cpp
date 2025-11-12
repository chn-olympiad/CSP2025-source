#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(i==1&&j==1)
	cin>>r;
	else
	{
		int x;
		cin>>x;
		if(x>r)
		cnt++;
	}
	int x=1,y=1;
	for(int i=1;i<=cnt;i++)
	{
	if(x%2==1)
	y++;
	else
	y--;
	if(y==0)
	{
		x++;
		y=1;
	}
	if(y==n+1)
	{
		y=n;
		x++;
	}
	}
	cout<<x<<" "<<y;
	return 0;
}
