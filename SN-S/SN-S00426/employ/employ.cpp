#include<bits/stdc++.h>
using namespace std;
int n,m,ans,pan,cnt;
string s;
int c[505],dis[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(s[1]=='0') pan=1;
	for(int i=2;i<=s.size();i++)
	{
		if(s[i]=='0') pan=1;
		if(s[i-1]=='0') dis[i]=dis[i-1]+1;
		else dis[i]=dis[i-1];
	}
	if(pan==0)
	{
		sort(c+1,c+1+n);
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				cnt++;
				continue;
			}
			if(cnt<c[i]) 
			{
				long long lin=1;
				for(int j=1;j<=n;j++)
				{
					lin=(lin*j)%998244353;
				}
				ans=(ans+lin%998244353;
			}
			else
			{
				long long lin=1;
				for(int j=1;j<=n-1;j++)
				{
					lin=(lin*j)%998244353;
				}
				ans=(ans+(lin*c[i])%998244353)%998244353;
				for(int j=c[i]+1,k=1;j<=n,k<=cnt;j++,k++)
				{
					long long linn=n-1-cnt;
					for(int q=1;q<=j-1-k;q++)
					{
						linn=linn*linn%998244353;
						linn--;
					}
					for(int i=1;i<=n-j;i++)
					{
						
					}
				}
			}
		}
	}
	return 0;
}
