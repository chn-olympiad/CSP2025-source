#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=510,MOD=998244353;
int c[N];
int ans=0;
int a[N],fac[N];
bool vis[N];
string s;
int n,m;
bool check()
{
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<"a[i]="<<a[i]<<" c[a[i]]="<<c[a[i]]<<" s[i]="<<s[i]<<" cnt1="<<cnt1<<endl;
		if(cnt1>=c[a[i]]||s[i-1]=='0') cnt1++;
		else cnt2++;
	}
//	cout<<endl;
	return cnt2>=m;
}
void dfs(int step)
{
	if(step>n)
	{
		if(check())
		{
//			for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//			cout<<endl;
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=500;i++) fac[i]=fac[i-1]*i%MOD;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<endl;
	}
	else if(m==n)
	{
		bool flag=1;
		int len=s.size();
		for(int i=0;i<len;i++) if(s[i]=='0') flag=0;
		for(int i=1;i<=n;i++) if(c[i]==0) flag=0;
		if(flag==1) cout<<fac[n]<<endl;
		else cout<<0<<endl;
	}
	else if(m==1)
	{
		bool flag=0;
		int len=s.size();
		for(int i=0;i<len;i++) if(s[i]=='1') flag=1;
		if(!flag) cout<<0<<endl;
		else
		{
			int ans=0;
			for(int i=0;i<len;i++)
			{
				if(s[i]=='1')
				{
					int cnt=0;
					for(int j=1;j<=n;j++)
					{
						if(c[j]>i) cnt++;
					}
					ans+=(cnt*fac[n-i-1]%MOD);
					ans%=MOD;
				}
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=(c[i]>0);
		cout<<cnt<<endl;
		if(cnt<m) cout<<0<<endl;
		else cout<<fac[n]<<endl;
	}
	return 0;
}