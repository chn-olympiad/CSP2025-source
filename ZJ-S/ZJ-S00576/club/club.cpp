/*
¿ªlong long
¿ªfreopen
*/
#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100005][5];
long long b[100005];
long long dp[10005][10005];
/*
long long ans = 0;
void AAA(long long x,long long c1,long long c2,long long c3,long long sum)
{
//	cout<<x<<" "<<c1<<" "<<c2<<" "<<c3<<"\n";
	ans = max(ans,sum);
	if(x>n) return;
	if(c1<n/2) AAA(x+1,c1+1,c2,c3,sum+a[x][1]);
	if(c2<n/2) AAA(x+1,c1,c2+1,c3,sum+a[x][2]);
	if(x-c1-c2-1<n/2) AAA(x+1,c1,c2,c3+1,sum+a[x][3]);
}
*/
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long q;
	cin>>q;
	while(q--)
	{
		memset(dp,0,sizeof dp);
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
//		ans = 0;
//		AAA(1,0,0,0,0);
//		cout<<ans<<"\n";
		if(n<=20000)
		{
			long long ans = 0;
			for(long long i=1;i<=n;i++)
			{
				for(long long c1=min(i,n/2);c1>=0;c1--)
				{
					for(long long c2=min(i-c1,n/2);c2>=0;c2--)
					{
						long long c3 = i-c1-c2;
						if(c3>n/2) break;
						if(c3) dp[c1][c2] = max(dp[c1][c2],dp[c1][c2]+a[i][3]);
						if(c1) dp[c1][c2] = max(dp[c1][c2],dp[c1-1][c2]+a[i][1]);
						if(c2) dp[c1][c2] = max(dp[c1][c2],dp[c1][c2-1]+a[i][2]);
						ans = max(ans,dp[c1][c2]);
//						cout<<c1<<" "<<c2<<" "<<c3<<" "<<dp[c1][c2]<<"\n";
					}
				}
			}
			cout<<ans<<"\n";
		}
		else 
		{
			for(long long i=1;i<=n;i++) b[i] = a[i][1];
			sort(b+1,b+1+n,greater<long long>());
			long long ans = 0;
			for(long long i=1;i<=n/2;i++) ans += b[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}

