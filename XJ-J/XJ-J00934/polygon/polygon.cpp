#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int i,n,a[10005]={0},s=-1,t;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
	s=max(s,a[i]);
	t+=a[i];	
	}
	if(n==3&&t>2*s)
	{
	cout<<1;	
	return 0;
	}
	else
	{
	cout<<0;	
	return 0;
	}
	return 0;
}
