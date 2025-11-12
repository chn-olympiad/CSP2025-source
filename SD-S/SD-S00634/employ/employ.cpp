#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,num;
int a[1000005],c[1000005],sum[1000005],vis[1000005];
string s;
int ans;
void dfs(int num)
{
	if(num>n)
	{
		int tmp=0,num2=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i]<<" ";
			//cout<<c[a[i]]<<" "<<sum[i-1]<<endl;
			if(c[a[i]]>num2&&s[i-1]=='1')
			{
				
				tmp++;
			}
			else{
				num2++;
			}
		}
		//cout<<endl;
		if(tmp>=m)
		{
			
			ans++;
			ans%=998244353;
		}
	}
	else{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				a[num]=i;
				vis[i]=1;
				dfs(num+1);
				vis[i]=0;
				a[num]=0;
			}
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if(s[i]=='0')sum[i]++;
	}
	if(sum[n]==n)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		ans=1;
		if(sum[n]==0)
		{
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
		}
		else
		ans--;
		cout<<ans;
		return 0; 
	}
	if(sum[n]==0)
	{
		int numm=0;
		for(int i=1;i<=n;i++)
		if(c[i]==0)numm++;
		if(numm>n-m)
		{
			cout<<0;
			return 0;
		}
	    ans=0;
	    int tmp=1;
		for(int i=1;i<=n-numm;i++)//¼¸¸ö0 
		{
			tmp*=n-i+1;
			tmp%=998244353;
		}
		cout<<tmp;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

