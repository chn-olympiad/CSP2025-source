#include <bits/stdc++.h>
using namespace std;
int n,m,a[100+10],z,x,y,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]!=ans) z++;
		else x=i;
	}
	x=n*m+1-x;
	if(x<=n) 
	{
		cout<<"1 "<<x;	
		return 0;
	}
	else
	{
		y=x/n+1;
		if(y%2==1)
		{
			cout<<y<<" "<<x%n;	
		}
		else
		{
			cout<<y<<" "<<m*n-x%n-1;	
		}
	}
	return 0;	
}
