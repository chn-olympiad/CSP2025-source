#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll sum=0,l=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')l=-1;c=getchar();}
	while(isdigit(c)){sum=(sum<<1)+(sum<<3)+(c^48);c=getchar();}
	return sum*l;
}
const ll pr=37,mod=1e9+7,n=5e6;
ll qk[5001000],c[200100],ls[200100],tot,sm[200100],ans[200100];
int ch[5001000][28],fi[5001000],cnt;
vector<int> v[5001000],l[5001000];
string s[200100];
struct Node
{
	int x,id;
};
vector<Node> q[5001000];
void Add(string s,ll x)
{
	ll sz=s.size();
	ll now=0;
	for(ll i=0;i<sz;i++)
	{
		ll nw=s[i]-'a'+1;
		if(!ch[now][nw])ch[now][nw]=++cnt;
		now=ch[now][nw];
	}
	v[now].push_back(x);
}
void Build()
{
	queue<ll> q;
	for(ll i=1;i<=26;i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		l[fi[x]].push_back(x);
		for(ll i=1;i<=26;i++)
		{
			if(ch[x][i])fi[ch[x][i]]=ch[fi[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fi[x]][i];
		}
	}
}
ll qp(ll a,ll b)
{
	ll c=1;
	while(b)
	{
		if(b&1)c=c*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return c;
}
void dfs(ll x)
{
	for(auto p:v[x])sm[p]++;
	for(auto p:q[x])ans[p.id]+=sm[p.x];
	for(auto v:l[x])dfs(v);
	for(auto p:v[x])sm[p]--;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(ll i=qk[0]=1;i<=n;i++)qk[i]=qk[i-1]*pr%mod;
	ll a=read(),b=read();
	for(ll i=1;i<=a;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		s[i]=s1;
		ll sz=s1.size(),nw1=0,nw2=0;
		for(ll j=0;j<sz;j++)nw1=(nw1*pr+s1[j]-'a'+1)%mod,nw2=(nw2*pr+s2[j]-'a'+1)%mod;
		ls[++tot]=c[i]=(nw1-nw2+mod)%mod;
	}
	sort(ls+1,ls+tot+1);
	tot=unique(ls+1,ls+tot+1)-ls-1;
	for(ll i=1;i<=a;i++)
	{
		c[i]=lower_bound(ls+1,ls+tot+1,c[i])-ls;
		Add(s[i],c[i]);
	}
	Build();
	for(ll i=1;i<=b;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll sz=s1.size(),nw1=0,nw2=0;
		for(ll j=0;j<sz;j++)nw1=(nw1*pr+s1[j]-'a'+1)%mod,nw2=(nw2*pr+s2[j]-'a'+1)%mod;
		ll nw=(nw1-nw2+mod)%mod*qp(qk[sz],mod-2)%mod,now=0;
		for(ll j=0;j<sz;j++)
		{
			nw=nw*pr%mod;
			now=ch[now][s1[j]-'a'+1];
			ll x=lower_bound(ls+1,ls+tot+1,nw)-ls;
			if(ls[x]!=nw)continue;
			q[now].push_back((Node){x,i});
		}
	}
	dfs(0);
	for(ll i=1;i<=b;i++)cout<<ans[i]<<"\n";
	return 0;
}
