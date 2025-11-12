#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define NFOR(i,j,k) for(int i=(j);i>=(k);--i)
#define fst first
#define sec second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
int read()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1,c=getchar();}
	while(c>='0'&&c<='9') {s=(s<<1)+(s<<3)+c-'0';c=getchar();}
	return s*w;
}
void file(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
namespace modi
{
	const int mod=998244353;
	ll mulmod(ll a,ll b) {return 1ll*a*b%mod;}
	ll addmod(ll a,ll b) {return (a+b)%mod;}
	ll delmod(ll a,ll b) {return (a-b+mod)%mod;}
}
using namespace modi;
const int N=505;

int n,m;
//char s[N];
int hd[N];
int c[N];
ll ans;

int a[N],vis[N];

void sov()
{
	int cur=0,ret=0;
	FOR(i,1,n)
	{
		cur+=hd[i];
		if(c[a[i]]<=cur) ret++;
	}
	if(ret>=m) ans++;
}

void dfs(int x)
{
	if(x==n+1) 
	{
		sov();
		return;
	}
	FOR(i,1,n)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}

int main()
{
	file("employ");
	n=read();m=read();
	string s;
	cin>>s;
	FOR(i,0,n-1) hd[i]=s[i]-'0';
	FOR(i,1,n) c[i]=read();
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*
3 2
101
1 1 2

*/
