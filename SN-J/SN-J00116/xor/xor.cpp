#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;
ll m,n,a[100001],x,xn,xc,xcy,xcv,xx;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			//cout<<i;
			xn=n*m-i+1;
			break;
		}
	}
	xc=(xn-xn%n)/n;
	xcy=xn%n;
	if(xcy==0)
	{
		xcy=xn;
	}
	xcv=xc%2;
	//cout<<xcy;
	if(xcv==1)
	{
		xx=xcy;
	}
	if(xcv==0)
	{
		xx=n-xcy+1;
	}
	cout<<xc<<" "<<xx;
	return 0;
}
