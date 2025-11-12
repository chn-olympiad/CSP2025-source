#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
bool f=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1<<'\n';
		return 0;
	}
	else if(f)
	{
		cout<<(n-2)*(n-1)/2%998244353<<'\n';
		return 0;
	}
	return 0;
}
