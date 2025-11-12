#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int b=3;b<=n;b++)
	{
		int x=n-b+1;
		for(x=n-b+1;x>=1;x--)
			for(int i=x;i>=1;i--)ans=(ans+i)%998244353;
	}
	cout<<ans;
	return 0;
}
