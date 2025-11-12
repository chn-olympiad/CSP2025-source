#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a;
ll ans[1000005],tot;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(ll i=0; i<=a.size(); i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			ans[tot++]=a[i]-48;
		}
	}
	sort(ans,ans+tot,cmp);
	for(ll i=0; i<tot; i++)
	{
		cout<<ans[i];
	}
	return 0;
}
