//8
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans=1;
string s;
int a[505],vis[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	if(m==n)
	{
		int flag=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			cout<<"0";
		}
		else
		{
			flag=1;
			for(int i=1;i<=n;i++)
			{
				if(!a[i])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				for(int i=1;i<=n;i++)
				{
					ans=(1ll*ans*i)%mod;
				}
				cout<<ans;
			}
			else
			{
				cout<<"0";
			}
		}
		return 0;
	}
	else if(m==1)
	{
		int flag=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<"0";
		}
		else
		{
			flag=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i])
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				for(int i=1;i<=n;i++)
				{
					ans=(1ll*ans*i)%mod;
				}
				cout<<ans;
			}
			else
			{
				cout<<"0";
			}
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}