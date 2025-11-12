#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={0},cnt=1,c,r;
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[0])
		{
			cnt++;
		}
	}
	if(cnt%n==0)
	{
		c=cnt/n;
		if(c%2==0)
		{	
			r=1;
		}
		else
		{
			r=m;
		}
	}
	else
	{
		c=cnt/n+1;
		if(c%2==0)
		{	
			r=m-cnt%n+1;
		}
		else
		{
			r=cnt%n;
		}
	}
	cout<<c<<" "<<r;
	
	return 0;
}
