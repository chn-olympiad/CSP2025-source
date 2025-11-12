#include<bits/stdc++.h>

using namespace std;
#define int long long 

const int N=515;
const int mod=998244353;

int f[N][N];
int cntt[N];
bool tag[N];
bool fl=1;
int n,m,ans;
string s;
int a[N];
int pre[N],invpre[N];

bool cmp(int x,int y)
{
	return x<y;
}

void solve()
{
//	int cnt=0;
//	for(int i=1;i<=n;i++)
//		if(a[i]<=0) cnt++;
//	if(n-cnt>=m)
//		cout<<pre[n]<<endl;
//	else 
		cout<<0<<endl;
}

int quick_pow(int x,int k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}

void init()
{
	pre[0]=1;
	invpre[0]=1;
	for(int i=1;i<N;i++)
		pre[i]=pre[i-1]*i%mod;
	invpre[N-1]=quick_pow(pre[N-1],mod-2);
	for(int i=N-2;i>=1;i--)
		invpre[i]=invpre[i+1]*(i+1)%mod;
}

int C(int n,int m)
{
	return pre[n]*invpre[n-m]%mod*invpre[m]%mod;
}

void dfs(int now,int cnt)
{
	if(now==n+1)
	{
		if(n-cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(tag[i]) continue;
		if(cnt>=a[i]||s[now]=='0')
		{
			if(n-cnt-1>=m)
			{
				tag[i]=1;
				dfs(now+1,cnt+1);
				tag[i]=0;
			}
		}
		else 
		{
			tag[i]=1;
			dfs(now+1,cnt);
			tag[i]=0;
		}
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	cin>>n;
	cin>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		if(s[i]=='0')
			fl=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(fl)
	{
		solve();
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}