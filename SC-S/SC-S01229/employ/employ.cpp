#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10,mod=998244353;
int n,m,cnt,pl[N],c[N],ans,ct[N];
char s[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n;i++)if(s[i]=='1')cnt++;
	if(cnt<m){cout<<"0"<<'\n';return 0;}//一定不合法的。
	if(n<=10)
	{
		for(int i=1;i<=n;i++)pl[i]=i;
		do
		{
			int res=0;
			for(int i=1;i<=n;i++)
				if(s[i-1]=='1'&&c[pl[i]]>i-1-res)res++;
			if(res>=m)ans=(ans+1)%mod;
		}while(next_permutation(pl+1,pl+n+1));
		cout<<ans<<'\n';
		return 0;
	} 
	if(n==m)
	{
		for(int i=1;i<=n;i++)if(c[i]==0)cnt--;
		if(cnt!=m)cout<<"0"<<'\n';
		else
		{
			ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans<<'\n';
		} 
		return 0;	
	} 
	if(m==1)
	{
		for(int i=1;i<=n;i++)ct[c[i]]++;
		for(int i=1;i<=n;i++)ct[i]+=ct[i-1];
		int res=1;ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		for(int i=1;i<=n-cnt;i++)res=res*i%mod;
		int gs=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1')
			{
				if(ct[i-1]-gs)res=res*(ct[i-1]-gs)%mod,gs++;
				else res=0;
			}
		}
		cout<<(ans-res+mod)%mod<<'\n';
	}
//	if(cnt==n)//特殊性质A
//	{
//		ans=1;
//		for(int i=1;i<=n;i++)ans=ans*i%mod;
//		cout<<ans<<'\n';
//		return 0;
//	} 
	return 0;
}