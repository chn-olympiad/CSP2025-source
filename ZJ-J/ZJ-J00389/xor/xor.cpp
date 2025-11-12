#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,num[505000],sum[505000],dp[1024][1024],book[505000],ans;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		if(num[i]==k)
		{
			ans++;
			book[i]=1;
		}
		sum[i]=sum[i-1]^num[i];
	}
	int tmp;
	for(int i=2;i<=n;i++)
	{
		tmp=0;
		for(int j=1;j<i;j++)
			if(book[j])
				tmp++;
		for(int j=1;j<=n;j++)
		{
			int p=j+i-1;
			if(p>n)
				break;
			if(book[j-1])
				tmp--;
			if(book[p])
				tmp++;
			if(tmp==0&&(sum[p]^sum[j-1])==k)
			{
				ans++;
				for(int g=j;g<=p;g++)
					book[g]=1;
				j=p;p=j+i-1;
				for(int g=j;g<=p;g++)
					if(book[g])
						tmp++;
			}
		}
	}
	cout<<ans;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>800)
	{
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		if(num[i]==0) i--,n--;
		sum[i]=sum[i-1]^num[i];
	}
	for(int l=1;l<=n;l++)
		dp[l][l]=(num[l]==k)?1:0;
	for(int l=2;l<=n;l++)
		for(int i=1;i<=n;i++)
		{
			int j=i+l-1;
			if(j>n) continue;
			for(int g=i+1;g<=j;g++)//[i,g)+[g,j]
				if(dp[i][j]<dp[i][g-1]+dp[g][j])
					dp[i][j]=dp[i][g-1]+dp[g][j];
			if((sum[j]^sum[i-1])==k&&dp[i][j]==0)
				dp[i][j]++;
		}
	cout<<dp[1][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
I'm luogu #737194.
I'm going to AFO.
I will never regret learning OI.
Before saying goodbye,
I will do everything I should.
Goodbye CCF,thank you for giving me a chance.
Goodbye luogu,thank you for your training.
Goodbye my teacher,thank you for lifting me up.
And finally,I will say goodbye to all of my friends and classmates.
Thank you for all you did for me.
I will remember the years I with OI.
return AFOed;

other thanks:
Thanks Soul_direction.
You are my friend forever.
Thanks ZHY(not luogu user).
You are always there for me.
Thanks SKS_Alcross_fred(not luogu user).
You usually study with me.
That gives me a strong power.
Thanks LQZ_Interglatic(not luogu user).
You have encouraged me when I want to kill myself.
You have saved my life for two times.
*/
