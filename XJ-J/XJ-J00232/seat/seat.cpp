#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sp=a[1];
	sort(a+1,a+n*m+1);
	int i;
	for(i=n*m;i>=1;i--)
	{
		if(a[i]==sp)
		{
			break;
		}
	}
	i=n*m-i+1;
	
	int k,h;
	if(i%n!=0)
	{
		k=i/n+1;
	}
	else
	{
		k=i/n;
	}
	if(k%2==0)
	{
		if(i%n==0)
		{
			h=1;
		}
		else
		{
			h=n-(i%n)+1;
		}
	}
	else
	{
		if(i%n==0)
		{
			h=n;
		}
		else
		{
			h=i%3;
		}
	}
	cout<<k<<' '<<h;
	return 0;
}
