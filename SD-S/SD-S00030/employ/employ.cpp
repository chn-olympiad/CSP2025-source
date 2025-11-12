#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rg register
#define INT_MAX 0x7fffffff
#define LL_INT_MAX 0x7fffffffffffffffll
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
namespace io
{
	template<typename T> inline void iread(T &x)
	{
		x=0; char c=' '; int w=1;
		while(!isdigit(c)&&c!='-') c=getchar();
		if(c=='-'){w=-1; c=getchar();}
		while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	}
}
#define mod 998244353
using io::iread;
const int N=505;
int n,m;
ll ans;
string sss;
ll p[N];
bool sr[N];
int c[N];
bool used[N];
void dfs(int s,int sum,int fail)
{
	if(n-s+1+sum<m||s>n+1) return ;
	if(sum==m)
	{
		ans=(ans+p[n-s+1])%mod;
		return ;
	}
	int tmp=ans;
	int st=upper_bound(c+1,c+n+1,fail)-c;
	for(int i=1;i<=n;++i)
	{
		if(!used[i])
		{
			used[i]=1;
			if(i<st||sr[s]==0) dfs(s+1,sum,fail+1);
			else dfs(s+1,sum+1,fail);
			used[i]=0;
		}
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>sss;
	p[0]=1ll;
	for(int i=1;i<=n;++i) p[i]=p[i-1]*i%mod;
	for(int i=1;i<=n;++i)
	{
		iread(c[i]);
		sr[i]=sss[i-1]-'0';
	}
	sort(c+1,c+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
