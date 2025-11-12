#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],s,x,y=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		s=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(y%2==1) x++;
		else x--;
		if(x>n&&y%2==1)
		{
			x=n;
			y++;
		}
		if(x<1&&y%2==0)
		{
			x=1;
			y++;
		}
		if(a[i]==s)
		{
			cout<<y<<" "<<x;
		}
	}
	return 0;
}
