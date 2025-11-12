#include<bits/stdc++.h>
using namespace std;
long long si;
int a[5001];
int s(int li,int h,int su)
{
	if(h<0 && su>=3)
	{
		si=(si+1)%(998244353);
	}
	for(int i=li-1;i>=1;i--)
	{
		s(i,h-a[i],su+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--)
	{
		s(i,a[i],1);
	}
	cout<<si;
	return 0;
}
