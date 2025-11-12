#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],d,d1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	d1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		
		d++;
		if(a[i]==d1)
		{
			break;
		}
	}
	int t,l;
	if(d/n==d*1.0/n)
	{
		
		t=d/n;
		if(t%2)
		{
			cout<<t<<" "<<n;
		}
		else
		{
			cout<<t<<" "<<1;
		}
	}
	else
	{
		t=d/n+1;
		l=d%n;
		if(t%2)
		{
			cout<<t<<" "<<l;
		}
		else
		{
			cout<<t<<" "<<n-l+1;
		}
	}
	return 0;
 } 
