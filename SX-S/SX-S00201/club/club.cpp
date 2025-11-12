#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll b[15];
ll a[100005][5],n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ll ans=0;
		cin>>n;
		for(ll i=1; i<=n; i++) for(ll j=1; j<=3; j++) cin>>a[i][j];
		for(ll i=1; i<=n; i++)
		{
			ll maxx=-100,id;
			for(ll j=1; j<=3; j++)
			{
				if(a[i][j]>=maxx)
				{
					if(a[i][j]==maxx)
					{
						if(b[maxx]>=b[j]) id=j;
					}
					else if(b[j]<=n/2) maxx=a[i][j],id=j;
				}
			}
			b[id]++;
			ans=ans+a[i][id];
		}
		cout<<ans;
	}
	return 0;
}
