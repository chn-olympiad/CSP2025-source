#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans=0,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=m*n;
	cin>>a[0];
	int z=a[0];
	for(int i=1;i<s;i++)
	{
		cin>>a[i];
	}
	sort(a,a+s);
	for(int i=0;i<s;i++)
	{
		if(a[i]==z)
		{
			break;
		}
		ans++;
	}
	ans=s-ans;
	if(ans%n!=0)
	{
		y=ans/n+1;
		if(y%2!=0)
		{
			x=ans%n;
		}else{
			x=-ans%n+n+1;
		}
	}else
	{
		y=ans/n;
		if(y%2!=0)
		{
			x=n;
		}else{
			x=1;
		}
	}
	cout<<y<<' '<<x;
	return 0;
 } 
