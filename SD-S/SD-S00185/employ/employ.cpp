#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<" is : "<<x<<endl
using namespace std;
const int mod=998244353;
int n,m,c[550],s[550],a[550],vis[550];
long long fra(int yu)
{
	long long cheng=1;
	for(int i=1;i<=yu;i++)
	{
		cheng*=i;
		cheng%=mod;
	}
	return cheng%mod;
}
long long power(long long aw,long long b)
{
	long long yu=b,ans=aw;
	while(yu)
	{
		if(yu&1)
		{
			ans*=aw,ans%=mod;
			yu^=1;
		}
		ans*=ans,yu>>=1;
		ans%=mod;
	}
	return ans%mod;
}
int lzy=0;
void dfs(int k)
{
	if(k>n)
	{
		int give=0,ac=0;
		for(int i=1;i<=n;i++)
		{
			if(give>=c[a[i]]||s[i]==0)give++;
			else ac++;
		}
		if(ac>=m)lzy++,lzy%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		a[k]=i;
		vis[i]=1;
		dfs(k+1);
		a[k]=0;
		vis[i]=0;
	}
	return;
}
bool isA=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int cnts=0;
	string h;
	cin>>h;
	for(int i=1;i<=n;i++)
	{
		s[i]=h[i-1]-'0';
		if(!s[i])isA=0;
		if(m==n&&s[i]==0)
		{
			cout<<0;
			return 0;
		}
		cnts+=s[i];
	}
	if(m==n)
	{
		cout<<fra(n);
		return 0;
	}
	int cntc0=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)cntc0++;
	}
	if(m==1)
	{
		int j=1;
		while(s[j]==0&&j<=n)j++;
		j--;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]>j)
			{
				cnt++;
			}
		}
		if(cnt>j)
		{
			cout<<fra(n);
			return 0;
		}
		else
		{
			long long res=fra(j)*power(fra(cnt)*fra(j-cnt)%mod,mod-2);
			res%=mod;
			cout<<(fra(n)-res+mod)%mod;
			return 0;
		}
	}
	if(isA)
	{
		cout<<cntc0<<" "<<fra(n-cntc0);
		return 0;
	}
	if(cnts<m)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<lzy;
	return 0;
}

