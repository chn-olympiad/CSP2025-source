#include<bits/stdc++.h>
using namespace std;
long long n,ans;
const int maxn=998244353;
int a[5005],qzh[5005];
int count(int p,int q)
{
	long long sup=1,sdown=1;
	for (int i=0;i<q;i++)
	{
		sup*=1ll*(p-i);
	}
	for (int i=1;i<=q;i++)
	 	sdown*=1ll*i;
	return sup/sdown;
}
int main()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort (a+1,a+1+n);
	if (n==3)
	{
		if (a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for (int i=3;i<=n;i++)
		ans+=count(n,i);
	cout<<ans%maxn;
	return 0;
}