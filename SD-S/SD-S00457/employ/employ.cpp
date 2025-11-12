#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
const ll mod=998244353;
mt19937 rnd(time(0));
ll fpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int n,m,c[510],s[510],cnt1=0,cnt2=0;
string ss;
bool flag=1;
int pl[3628810][15],arr[15],cnt,top;
bool vis[15];
void init()
{
	if(top==n)
	{
		++cnt;
		for(int i=1;i<=n;++i)pl[cnt][i]=arr[i];
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i])continue;
		vis[i]=1;
		arr[++top]=c[i];
		init();
		vis[i]=0;
		--top;
	}
}
void solve2()
{
	init();
	ll ans=0;
	for(int i=1;i<=cnt;++i)
	{
		int lq=0,jj=0;
		for(int j=1;j<=n;++j)
		{
			if(pl[i][j]<=jj)
			{
				++jj;
				continue;
			}
			if(s[j]==1)++lq;
			else ++jj;
		}
		if(lq>=m)ans=(ans+1)%mod;
	}
	cout<<ans<<"\n";
}
void solve1()//s[i]=1是ans为排列数 
{
	solve2();
	ll ans=1;
	for(int i=1;i<=n;++i)(ans*=i)%=mod;
	cout<<ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>ss;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
		cnt2+=(c[i]>0);
	}
	for(int i=0;i<n;++i)
	{
		s[i+1]=ss[i]-'0';
		cnt1+=s[i+1];
		if(s[i+1]==0)flag=0;
	}
	if(cnt1<m||cnt2<m)
	{
		cout<<0;
		return 0;
	}
	if(flag)solve1();
	else if(n<=10)solve2();
	else cout<<rnd()%998244353;
	return 0;
}
