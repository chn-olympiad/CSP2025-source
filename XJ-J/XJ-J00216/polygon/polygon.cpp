#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1001],s=0,maxn=-1;
bool v[1001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		maxn=max(a[i],maxn);
	}
	if(maxn*2<s)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
