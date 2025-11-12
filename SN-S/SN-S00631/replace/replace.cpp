#include<bits/stdc++.h>
#define ll long long 
#define maxn 5000005 
#define mod 998244353 
using namespace std;
ll n,Q,H1[maxn],H2[maxn],Hash1[maxn],Hash2[maxn],siz[maxn],inv[maxn],nxt[maxn];
string s1[maxn],s2[maxn];
vector<ll> q[maxn];
ll pw(ll x,ll T) 
{
	ll ret=1,tt=x;
	while(T)
	{
		if(T&1) ret=ret*tt%mod;
		T>>=1; tt=tt*tt%mod;
	}
	return ret;
}
ll cal1(ll l,ll r) {return (Hash1[r]-Hash1[l-1]+mod)*inv[l-1]%mod;}
ll cal2(ll l,ll r) {return (Hash2[r]-Hash2[l-1]+mod)*inv[l-1]%mod;}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("replace.in","r",stdin); freopen("replace.out","w",stdout);
	cin>>n>>Q; inv[maxn-1]=pw(pw(131,maxn-1),mod-2);
	for(int i=maxn-1;i>=1;i--) inv[i-1]=inv[i]*131LL%mod;
	ll flag=1;
	for(int i=1;i<=n;i++)
	{
		string s; cin>>s; ll sum1=0,sum2=0,tt=1,t1=0;
		for(auto j:s)
		{
			ll x=j-'a'+1; if(x!='a'&&x!='b') flag=0;
			if(x=='b') t1++;
			sum1=sum1+x*tt%mod; sum1%=mod; tt=tt*131LL%mod; 
		}
		if(t1!=1) flag=0;
		s1[i]=s; cin>>s; tt=1; s2[i]=s; t1=0;
		for(auto j:s)
		{
			ll x=j-'a'+1; if(x!='a'&&x!='b') flag=0;
			if(x=='b') t1++;
			sum2=sum2+x*tt%mod; sum2%=mod; tt=tt*131LL%mod; 
		}
		if(t1!=1) flag=0;
		H1[i]=sum1; H2[i]=sum2; siz[i]=s.size();
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			ll x,y;
			for(int j=0;j<s1[i].size();j++)
			{
				if(s1[i][j]=='b') x=j;
			}
			for(int j=0;j<s2[i].size();j++)
			{
				if(s2[i][j]=='b') y=j;
			}
			q[x-y+maxn/2].push_back(x);
		}
		for(int i=0;i<maxn;i++) sort(q[i].begin(),q[i].end());
		while(Q--)
		{
			string s1,s2; cin>>s1>>s2;
			ll x,y;
			for(int j=0;j<s1.size();j++)
			{
				if(s1[j]=='b') x=j;
			}
			for(int j=0;j<s2.size();j++)
			{
				if(s2[j]=='b') y=j;
			}
			ll tt=x-y+maxn/2;
			ll l=0,r=q[tt].size(),ans=0;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(q[tt][mid]<=x) l=mid+1,ans=mid;
				else r=mid-1;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(n<=1000)
	{
		while(Q--)
		{
			string x,y; cin>>x>>y; ll len=x.size(),L=0,R=0; x='1'+x; y='1'+y;
			for(int i=1;i<=len;i++) if(x[i]!=y[i]) {L=i; break;}
			for(int i=len;i>=1;i--) if(x[i]!=y[i]) {R=i; break;}
			ll tt=1;
			for(int i=1;i<=len;i++)
			{
				ll t=x[i]-'a'+1;
				Hash1[i]=Hash1[i-1]+t*tt;
				Hash1[i]%=mod; tt=tt*131LL%mod;
			}
			tt=1;
			for(int i=1;i<=len;i++)
			{
				ll t=y[i]-'a'+1;
				Hash2[i]=Hash2[i-1]+t*tt;
				Hash2[i]%=mod; tt=tt*131LL%mod;
			}
			ll ans=0;
			for(int i=1;i<=L;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i+siz[j]-1>=R&&i+siz[j]-1<=len&&cal1(i,i+siz[j]-1)==H1[j]&&cal2(i,i+siz[j]-1)==H2[j]) ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0; 
	}
	while(Q--)
	{
		string x,y; cin>>x>>y; ll len=x.size(),L=0,R=0; x='1'+x; y='1'+y;
		for(int i=1;i<=len;i++) if(x[i]!=y[i]) {L=i; break;}
		for(int i=len;i>=1;i--) if(x[i]!=y[i]) {R=i; break;}
		nxt[L]=L;
		for(int i=L+1;i<=R;i++)
		{
			ll j=nxt[i-1];
			while(j&&x[j+1]!=x[i]) j=nxt[j];
			if(x[j+1]==x[i]) nxt[i]=j+1;
			else nxt[i]=L;
		}
		for(int i=1;i<=n;i++) s1[i]='1'+s1[i];
		ll tt=1;
		for(int i=1;i<=len;i++)
		{
			ll t=x[i]-'a'+1;
			Hash1[i]=Hash1[i-1]+t*tt;
			Hash1[i]%=mod; tt=tt*131LL%mod;
		}
		tt=1;
		for(int i=1;i<=len;i++)
		{
			ll t=y[i]-'a'+1;
			Hash2[i]=Hash2[i-1]+t*tt;
			Hash2[i]%=mod; tt=tt*131LL%mod;
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll siz=s1[i].size(); siz--; ll num=L;
			for(int j=1;j<=siz;j++)
			{
				if(x[num]==s1[i][j]) num++;
				if(num==R+1)
				{
					ll l=R-j+1,r=l+siz-1;
					if(l>=1&&r<=len&&cal1(l,r)==H1[i]&&cal2(l,r)==H2[i]) ans++;
					num=nxt[num];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
