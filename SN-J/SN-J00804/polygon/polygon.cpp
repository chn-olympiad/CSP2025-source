#include<bits/stdc++.h>
#define ll long long
#define inf 5005
using namespace std;
int n;
int a[inf];
ll ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		ans=ans*2;
		if(ans>998244353ll) ans=ans-998244353ll;
	}
	ans=ans-1;
	if(ans<0) ans=ans+998244353ll;
	ans=ans-n;
	if(ans<0) ans=ans+998244353ll;
	ans=ans-n*(n-1)/2;
	if(ans<0) ans=ans+998244353ll;
	cout<<ans;
	return 0;
}
