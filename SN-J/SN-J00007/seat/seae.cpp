#include<bits/stdc++.h>
using namespace std;
long long a[101];
long long n,m,x=1,e,l=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		long long e=a[1];
		if(a[i]>e)
		{
			l++;
		}
	}
	if(l>m)
	{
		while(l>m)
	{
		x++;
		l=l-m;
	}
	}
	if(x%2==0)
	{
		cout<<x<<" "<<m-(l-1);
	}
	else
	{
		cout<<x<<" "<<l;
	}
	return 0;
 } 
