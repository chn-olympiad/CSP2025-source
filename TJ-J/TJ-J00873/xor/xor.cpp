#include<bits/stdc++.h>
using namespace std;
int a[10009];
int dp[1009][1009];
int b[10009];
int huo(int x,int y)
{
	int p=0;
	string s,sp;
	while(x!=0)
	{
		s+=x%2;
		x/=2;
	}
	while(y!=0)
	{
		sp+=y%2;
		y/=2;
	}
	int len=s.size(),le=sp.size();
	len--;
	le--;
	int q=max(len,le);
	for(int i=0;i<=q;i++)
	{
		if(s[i]!=sp[i])
		{
			p+=pow(2,i);
		}
		else
		{
			continue;
		}
	}
	return p;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=a[i];
	}
	for(int i=2;i<=n;i++)
	{
		dp[i-1][i]=huo(a[i-1],a[i]);
	}
	for(int len=2;len<=n;len++)
	{
		for(int j=1;j+len<=n;j++)
		{
			dp[j][j+len]=huo(dp[j][j+len-1],a[j+len]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]==m&&ans==0)
			{
				for(int k=i;k<=j;k++)
				{
					b[k]=1;
				}
				ans++;
			}
			else
			{
				if(dp[i][j]==m)
				{
					bool flag=true;
					for(int k=i;k<=j;k++)
					{
						if(b[k]==1)
						{
							flag=false;
						}
					}
					if(!flag)
					{
						continue;
					}
					else
					{
						ans++;
						for(int k=i;k<=j;k++)
						{
							b[k]=1;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

