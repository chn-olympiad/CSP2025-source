#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,m,ans,cnt;
string s;
int c[505],flag[505],flag1;
void dfs(int step,int cnt,int cnt2)
{
	if(step==n+1)
	{
		if (cnt2>=m)
		{
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			if (s[step-1]=='0'||cnt>=c[i])
			{
				dfs(step+1,cnt+1,cnt2);
			}
			else
			{
				dfs(step+1,cnt,cnt2+1);
			}
			flag[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			flag1=1;
			break;
		}
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(flag1==0)
	{
		for (int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				cnt++;
			}
			if(n-cnt<m)
			{
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for (int i=1;i<=n;i++)
		{
			ans=ans*i;
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
