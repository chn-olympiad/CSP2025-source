#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll t;
ll n;
struct node{
	ll fi;
	ll se;
	ll tag1;
};
node ma[N];
ll difs[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr);
	cin>>t;
	while(t--)
	{   
	    memset(difs,0,sizeof(difs));
        ll on=0,tw=0,th=0;
        ll ans=0;
	    cin>>n;
	    for(ll i=1;i<=n;i++)
	    {
	        ll a,b,c;
	        cin>>a>>b>>c;
	        ma[i].fi=max(b,a);
	        ma[i].fi=max(ma[i].fi,c);
	        if(ma[i].fi==a) 
			{
				on++;
				ma[i].se=max(b,c);
				ma[i].tag1=1;
			}
	        else if(ma[i].fi==b) 
			{
				tw++;
				ma[i].se=max(a,c);
				ma[i].tag1=2;
			}
			else if(ma[i].fi==c) 
	        {
	        	th++;
	        	ma[i].se=max(b,a);
	        	ma[i].tag1=3;
			}
		}
		ll maxn=max(on,tw);
		maxn=max(maxn,th);
		for(ll i=1;i<=n;i++) ans+=ma[i].fi;
		if(maxn>n/2)
		{
			ll tag;
			if(maxn==on) tag=1;
			else if(maxn==tw) tag=2;
			else if(maxn==th) tag=3;
			ll dif=maxn-n/2;
			for(ll i=1;i<=n;i++)
			{
				if(tag==ma[i].tag1) difs[i]=ma[i].fi-ma[i].se;
				else difs[i]=1e10+1;
			} 
			sort(difs+1,difs+1+n);
			for(ll i=1;i<=dif;i++) ans-=difs[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
