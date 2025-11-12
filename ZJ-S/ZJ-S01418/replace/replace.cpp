#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define prr pair<pr,pr>
#define fi first
#define se second
#define N 2005
#define M1 998244353ll
#define M2 998244853ll
#define B1 29
#define B2 31
using namespace std;
ll mi1[N],mi2[N];
pr uu[N],vv[N];
map<prr,ll>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,q;
	cin>>n>>q;
	mi1[0]=mi2[0]=1;
	for(ll i=1;i<N;i++)mi1[i]=mi1[i-1]*B1%M1,mi2[i]=mi2[i-1]*B2%M2;
	for(ll i=1;i<=n;i++){
		pr u,v;
		string s;
		cin>>s;
		ll p=s.length();
		s=" "+s;
		for(ll i=1;i<=p;i++)u.fi=(u.fi*B1+s[i]-'a')%M1,u.se=(u.se*B2+s[i]-'a')%M2;
		cin>>s;
		s=" "+s;
		for(ll i=1;i<=p;i++)v.fi=(v.fi*B1+s[i]-'a')%M1,v.se=(v.se*B2+s[i]-'a')%M2;
		mp[{u,v}]++;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		a=" "+a,b=" "+b;
		if(a.length()!=b.length()){
			cout<<"0\n";
			continue;
		}
		ll p=a.length();ll ans=0;
		for(ll i=1;i<=p;i++)uu[i].fi=(uu[i-1].fi*B1+a[i]-'a')%M1,uu[i].se=(uu[i-1].se*B2+a[i]-'a')%M2;
		for(ll i=1;i<=p;i++)vv[i].fi=(vv[i-1].fi*B1+b[i]-'a')%M1,vv[i].se=(vv[i-1].se*B2+b[i]-'a')%M2;
		for(ll i=1;i<=p;i++)for(ll j=i;j<=p;j++){
			pr x,y;
			x={(uu[p].fi-uu[j].fi*mi1[p-j]%M1+M1)%M1,(uu[p].se-uu[j].se*mi2[p-j]%M2+M2)%M2};
			y={(vv[p].fi-vv[j].fi*mi1[p-j]%M1+M1)%M1,(vv[p].se-vv[j].se*mi2[p-j]%M2+M2)%M2};
			if(x!=y)continue;
			x={uu[i].fi,uu[i].se};
			y={vv[i].fi,vv[i].se};
			if(x!=y)continue;
			x={(uu[j].fi-uu[i-1].fi*mi1[j-i+1]%M1+M1)%M1,(uu[j].se-uu[i-1].se*mi2[j-i+1]%M2+M2)%M2};
			y={(vv[j].fi-vv[i-1].fi*mi1[j-i+1]%M1+M1)%M1,(vv[j].se-vv[i-1].se*mi2[j-i+1]%M2+M2)%M2};
			ans+=mp[{x,y}];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
