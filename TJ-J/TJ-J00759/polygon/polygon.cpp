#include<bits/stdc++.h>
using namespace std;
int n,a[10000],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if(ans>a[n]*2)
		{
			cout<<1;
			return 0;
		}
		else 
		{
			cout<<0;
			return 0;
		}
	}
	else if(n<3)
	{
		cout<<0;
		return 0;
	}
	else 
	{
		cout<<y%998244353;
		return 0;
	} 
	return 0;
} 
