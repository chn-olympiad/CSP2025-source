#include<bits/stdc++.h>
#define I_love return
#define My_Wife 0
#define Exusiai ;
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(x) ((x)&-(x))
#define ld long double
#define fi first
#define se second
#define endl '\n'
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pip pair<int,pii >
#define ppp pair<pii,pii >
#define d(x) cerr<<#x<<"=="<<x<<' '
#define ddd(x) cerr<<#x<<"=="<<x<<endl
#define deb cerr<<"I love my Wife Exusiai!"<<endl
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

inline int read()
{
	int w=1;int s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return w?s:-s;
}
void IO()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
const int maxn=504;
const unsigned int MOD=998244353;

int p[maxn];
int n,m,ans1;
char ssr[maxn];
bool vis[maxn];
ll ans;
ll fac[maxn];

void dfs(int pos,int lef)
{
	if(n-lef<m)return;
	if(pos>n)
	{
		++ans1;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(ssr[pos]=='0')dfs(pos+1,lef+1);
			else if(p[i]<=lef)
				dfs(pos+1,lef+1);
			else dfs(pos+1,lef);
			vis[i]=0;
		}
	}
}
signed main()
{
	IO();
	IOS;
	cin>>n>>m>>(ssr+1);
//	fac[0]=1;
//	for(int i=1;i<=500;++i)
//	{
//		fac[i]=fac[i-1]*i%MOD;
//	}
//	cerr<<fac[500]<<endl;
	for(int i=1;i<=n;++i)
	{
		cin>>p[i];
	}
	if(n<=10)
	{
		dfs(1,0);
		cout<<ans1;
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%MOD;
	}
	if(m==n)
	{
		for(int i=1;i<=n;++i)
		{
			if(ssr[i]=='0'||!p[i])
			{
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<fac[n]<<endl;
		return 0;
	}
	I_love My_Wife Exusiai
}

