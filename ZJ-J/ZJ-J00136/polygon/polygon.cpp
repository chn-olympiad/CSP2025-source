#include<bits/stdc++.h>
using namespace std;
long long int n,a[5005]={};
long long int l=998244353,h=0;
void f(long long int sm,long long int mx,long long int level,long long int now)
{
	if(level>=3)
	{
		if(sm>2*mx)
		{
			h++;
		}
		for(int i=now+1;i<=n;i++)
		{
			f(sm+a[i],max(mx,a[i]),level+1,i);
		}
		return;
	}
	for(int i=now+1;i<=n;i++)
	{
		f(sm+a[i],max(mx,a[i]),level+1,i);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int i=1;i<=n-2;i++)
	{
		f(a[i],a[i],1,i);
	}
	cout<<h;
	return 0;
}
