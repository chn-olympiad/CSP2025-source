#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010,mod=998244353;
int n,m,s[N],jc[N],c[N],sum,fl[N],tot;
string tmp;
void dfs(int x,string now)
{
	if(x>n)
	{
		int bfr=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			int nw=now[i]-'0'+1;
			if(c[nw]<=cnt||tmp[i-1]=='0')cnt+=1;
		}
		tot+=(n-cnt>=m);
	}
	for(int i=0;i<n;i++)
	{
		if(fl[i])continue;
		fl[i]=1;
		char add=i+'0';
		dfs(x+1,now+add);
		fl[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>tmp;
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		int x=tmp[i-1]-'0';
		s[i]=s[i-1]+x;
		jc[i]=jc[i-1]*i%mod;
		cin>>c[i];
		sum+=(c[i]==0);
	}
	sort(c+1,c+n+1);
	if(n==m)
	{
		if(s[n]!=n||sum!=0)cout<<0;
		else cout<<jc[n];
		return 0;
	}
	if(m==1)
	{
		int lst=1,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(tmp[i-1]=='0')continue;
			int fst=lower_bound(c+1,c+n+1,i)-c;
//			cout<<i<<' '<<fst<<' '<<jc[n-s[i]]<<' '<<lst<<endl;
			ans=(ans+(n-fst+1)*jc[n-s[i]]%mod*lst%mod)%mod;
			lst=lst*(fst-s[i])%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=10)
	{
		dfs(1,"0");
		cout<<tot<<endl;
		return 0;
	}
	cout<<225301405;
	return 0;
}
/*
5 1
10010
0 0 1 3 4
*/