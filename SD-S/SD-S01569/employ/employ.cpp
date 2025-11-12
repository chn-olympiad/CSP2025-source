#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,c[502],dp[300000][20];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=1,cnt;i<(1<<n);i++)
		{
			cnt=0;
			for(int j=0;j<n;j++)if(i&(1<<j))cnt++;
			for(int j=0;j<=cnt;j++)for(int k=0,x;k<n;k++)if(i&(1<<k))
			{
				x=i^(1<<k);
				if(c[k]<=cnt-1-j||s[cnt-1]=='0')(dp[i][j]+=dp[x][j])%=mod;
				if(j&&c[k]>cnt-j&&s[cnt-1]=='1')(dp[i][j]+=dp[x][j-1])%=mod;
			}
		}
		for(int i=m;i<=n;i++)(ans+=dp[(1<<n)-1][i])%=mod;
	}
	else
	{
		ans=1;
		for(int i=0;i<n;i++)if(s[i]=='0'||c[i]==0){cout<<0;return 0;}
		for(int i=1;i<=n;i++)(ans*=i)%=mod;
	}
	cout<<ans;
}
/*
Ren5Jie4Di4Ling5%
Luogu Account:Butterfly_qwq(banned) strappple
100+100+30+24=254 i think this could 1=.
16:45 only 20pts...
17:00 get more 4pts back to C
17:55 finish 24pts,why wrong?
18:10 pass 24pts,back to C
*/
