#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,q;
string sa[N],sb[N];
int main()
{
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		cin>>sa[i]>>sb[i];
		cout<<sa[i]<<" "<<sb[i]<<"\n";
	}
	while(q--)
	{
		ll ans=0;
		string ta,tb;
		cin>>ta>>tb;
		ll lena=ta.length();
		ll x=-1;
		for(ll i=0;i<lena;i++)
		{
			if(ta[i]!=tb[i])
			{
				x++;
				difa[x]=ta[i];
				difb[x]=tb[i];
			}
		}
		for(ll i=1;i<=n;i++)
		{
			if(difa==sa[i]&&difb==sb[i]) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
