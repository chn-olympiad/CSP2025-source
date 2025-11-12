#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int s[N],dp[N],a[N],b[(1<<20)+1];
int maxn;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		maxn=max(maxn,a[i]);
	}
	if(maxn<=1)
	{
		int ans=0;
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
		}
		else
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++,cnt=0;
				else
				{
					cnt++;
					if(cnt%2==0) ans++;
				}
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[s[i-1]]=i-1;
		dp[i]=dp[i-1];
		if(b[(s[i]^k)]!=0) dp[i]=max(dp[i],dp[b[(s[i]^k)]]+1);
		/*for(int j=i;j>=1;j--)
		{
			if((s[i]^s[j-1])==k)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}*/
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
