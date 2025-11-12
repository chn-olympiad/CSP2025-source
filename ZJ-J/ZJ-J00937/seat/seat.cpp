#include<bits/stdc++.h>
using namespace std;
int n,m,s,p=1,x,y;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	cin>>a[1];
	for(int i=2;i<=s;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])	p++;
	}
	x=p/n;
	if(p%n>0)
	{
		x++;
	}
	cout<<x<<" ";
	if(x%2==1)
	{
		if(p%n==0)
		{
			cout<<n;
			return 0;
		}
		cout<<p%n;
	}
	else
	{
		if(p%n==0)
		{
			cout<<"1";
			return 0;
		}
		cout<<n-(p%n)+1;
	}
	return 0;
}