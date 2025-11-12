#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
bool tf(int l,int r)
{
	int ap=0;
	int m=0;
	for(int i=l;i<=r;i++)
	{
		ap+=a[i];
		m=max(m,a[i]);
	}
	return (ap-m>m) ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	if(n<=2)
	{
		cout << 0 ;
		return 0;
	}
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
		ma=max(ma,a[i]);
	}
	if(n==3)
	{
		cout << (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])));
		return 0;
	}
		for(int i=3;i<=n;i++)
		{
			ans+=(n-i+1);
			ans%=998244353;
		}
		if(ma==1) cout << ans ;
		else cout << ans/2 ;
		return 0;
}
