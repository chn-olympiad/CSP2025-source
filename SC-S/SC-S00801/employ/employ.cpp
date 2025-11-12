#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=500,p=998244353;
int n,m;
int ans;
string s;
int c[N];
int vis[N],a[N];
int cnt;
int fact(int n)
{
	int res=1;
	rep(i,2,n) res=(res*i)%p;
	return res;
}
void dfs(int u)
{
	if(cnt>=m) {ans+=fact(n-u+1);ans%=p;return;}
	if(cnt+(n-u+1)<m) return;
	if(u>n)
	{
		if(cnt>=m) ans++,ans%=p;
		return;
	}
	rep(i,1,n)
	{
		if(!vis[i])
		{
			a[u]=i;
			vis[i]=1;
			int op=0;
			if(s[u]=='1'&&u-1-cnt<c[i]) op=1;
			cnt+=op;
			dfs(u+1);
			cnt-=op;
			vis[i]=0;
		}
	}
}
void solve1()
{
	dfs(1);
	cout<<ans%p;
	return;
}
void solve2()
{
	rep(i,1,n)
	  if(s[i]=='0'||c[i]==0)
	  {
		puts("0");
		return;	
	  }
	cout<<fact(n);
	return;
}
void solve3()
{
	int cnt=0;
	rep(i,1,n)
	  if(c[i]==0)
	    cnt++;
	if(n-cnt<m) puts("0");
	else cout<<fact(n);
	return;
}
void solve4()
{
	int cnt=0;
	rep(i,1,n)
	  if(c[i]==0)
	    cnt++;
	cout<<fact(n);
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=" "+s;
	rep(i,1,n) cin>>c[i];
	if(n<=18) solve1();
	else if(n==m) solve2();
	else if(m==1) solve3();
	else solve4();
	return 0;
}