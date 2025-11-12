#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,c[N],vis[N],b[N],ans=0;
string s;
int qp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return res;
}
void work0()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	if(!c[i]) sum++;
}
void dfs(int step) 
{
	if(step==n+1) {
		int res=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			int j=s[i]-'0';
			if(c[b[i]]>sum&&j) res++;
			else sum++;
		}
		if(res>=m) ans++;
		if(ans>mod) ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) {
			vis[i]=1;
			b[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
void work1()
{
	dfs(1);
	cout<<ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	int flag=0;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		int j=s[i]-'0';
		if(!j) flag=1;
	}
	if(!flag) {
		work0();
		return 0;
	}
	if(n<=10) {
		work1();
		return 0;
	}
	return 0;
 } 
 /*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3 
 */
