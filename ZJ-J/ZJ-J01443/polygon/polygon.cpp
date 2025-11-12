#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
bool flag=true;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		int jilu=a[i-1];
		if(a[i]!=jilu)flag=false;
	}
	if(n<3)cout<<0;
	if(n==3)
	{
		if(a[1]+a[2]+a[3]<=max(a[1],max(a[2],a[3]))*2)cout<<0;
		else cout<<1;
		return 0;
	}
	if(flag)
	{
		int shang=1,xia=1;
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<i;j++)
			{
				shang=shang*(n-j);
				xia=xia*(j+1);
			}
			ans+=shang/xia;
			shang=1,xia=1;
		}
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
