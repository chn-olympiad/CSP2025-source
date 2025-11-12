#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,ans;
int a[505];
int c[505];
bool vis[105];
string s;
void dfs(int x)
{
	if(x==n+1)
	{
		int cnt=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[a[i]]||s[i-1]=='0') cnt++;
			else num++;
		}
		if(num>=m) ans++;
		ans%=MOD;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			a[x]=i;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m!=n)
	{
		dfs(1);
		cout<<ans;
	}
	else
	{
		bool flag=true;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='0')
			{
				flag=false;
				break;
			}
		}
		if(!flag) cout<<0;
		else
		{
			bool f2=true;
			for(int i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					f2=false;
					break;
				}
			}
			if(!f2) cout<<0;
			else
			{
				long long sum=1;
				for(int i=1;i<=n;i++) sum*=i,sum%=MOD;
				cout<<sum;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
