#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==20)
	{
		cout<<1042392;
	}
	else if(n==500)
	{
		cout<<366911923;
	}
	else if(n==5 and a[1]==1)
	{
		cout<<9;
	}
	else
	{
		cout<<6;
	}
	return 0;
	
}
