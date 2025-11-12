#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const ll mod=998244353;
int n,m,CNT;
ll s;
char ch[N];
int a[N],p[N],flg[N],t[N];
bool flag=1;
void dfs(int k)
{
	if(k>n)
	{
		int ans1=0,ans2=0;
		for(int i=1;i<=n;++i)
		  if(ch[i]=='1'&&ans2<a[p[i]]) ++ans1;
		  else ++ans2;
		if(ans1>=m) ++s;
		if(s>=mod) s-=mod;
	}
	for(int i=1;i<=n;++i)
	{
		if(flg[i]) continue;
		p[k]=i;
		flg[i]=1;
		dfs(k+1);
		p[k]=0;
		flg[i]=0;
	}
}
void A()
{
	int cnt1=0,cnt2=0;
	ll ans1=1,ans2=2;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	  if(a[i]==0) ++cnt1;
	cnt2=n-cnt1;
	if(cnt2<m)
	{
		printf("0");
		return ;
	}
	
}
void B()
{
	int cnt1=18,cnt2=n-18;
	if(m>18)
	{
		printf("0");
		return ;
	}
	ll opt=1;
	for(int i=cnt2;i>=19;--i)
	  opt*=i,opt%=mod;
	printf("%lld",opt);
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>ch[i];
		CNT+=ch[i]-'0';
		if(ch[i]=='0') flag=0;
	} 
	for(int i=1;i<=n;++i)
	  cin>>a[i];
	if(n<=18)
	{
		dfs(1);
		printf("%lld",s%mod);
		return 0;
	}
	if(flag)
	{
		A();
		return 0;
	}
	if(CNT<=18)
	{
		B();
		return 0;
	}
	return 0;
}
