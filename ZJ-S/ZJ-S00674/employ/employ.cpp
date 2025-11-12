#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353ll;
long long n,m;
string s;
long long p[505];
long long a[505];
bool vis[505];
long long ans;
bool flagA=true;
void dfs(int step)
{
	if(step>n)
	{
		int cnt=0;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				cnt++;
			}
			else
			{
				if(cnt>=a[p[i]])
				{
					cnt++;
				}
				else
				{
					res++;
				}
			}
		}
		if(res>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			p[step]=i;
			dfs(step+1);
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
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='1')
		{
			flagA=false;
		}
	}
	int kk=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			kk--;
		}
	}
	dfs(1);
	cout<<ans<<endl;
}

