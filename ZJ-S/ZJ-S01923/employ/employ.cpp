#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
const long long P=998244353;
long long n,m,a[505],p[505],cnt,sum=1,dp[12][4005][12];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	cin>>s;
	for(int i=0;i<s.size();i++) a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
	{
		p[i]=rd();
		cnt+=a[i];
	}
	if(cnt==n)
	{
		if(m==n)
		{
			for(int i=1;i<=n;i++) sum=sum*i%P;
			cout<<sum;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				for(int k=0;k<n;k++)
				{
					if(j>>k&1)
					{
						for(int l=0;l<=n;l++)
						{
							if(i-l-1>=p[k+1]||a[i]==0)
							{
								dp[i][j][l]=(dp[i][j][l]+dp[i-1][j^(1<<k)][l])%P;
							}
							else
							{
								dp[i][j][l+1]=(dp[i][j][l+1]+dp[i-1][j^(1<<k)][l])%P;
							}
						}
					}
				}
			}
		}
		sum=0;
		for(int j=m;j<=n;j++)
		{
			for(int i=0;i<(1<<n);i++)
			{
				sum=(sum+dp[n][i][j])%P;	
			}
		}
		cout<<sum;
	}
}
