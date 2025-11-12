#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while('0'>ch||ch>'9')
	{
		if(ch=='-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int inf = 1e18,N = 1e6 + 10;

struct stu
{
	int vul,cha,id,idd;
}a[N];

bool cmp(stu x,stu y)
{
	return x.cha > y.cha;
}

int n,tot,cnt[4],ans,sum[N][4];
int b[205][4],dp[205][205][205];
bool falg[N];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for(int T = read();T;T--)
	{
		n = read();
		if(n<=200)
		{
			for(int i = 1;i<=n;i++)
			{
				for(int j = 1;j<=3;j++)
				{
					b[i][j] = read();
				}
			}
			memset(dp,-0x3f3f3f3f,sizeof dp);
			dp[0][0][0] = 0;
			for(int i = 1;i<=n;i++)
			{
				for(int j = 0;j<=n/2;j++)
				{
					for(int k = 0;k<=n/2;k++)
					{
						if(i-j-k<=n/2)
						{
							if(j)
							{
								dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+b[i][1]);
							}
							if(k)
							{
								dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+b[i][2]);
							}
							if(i-j-k>0)
							{
								dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+b[i][3]);
							}
						}
					}
				}
			}
			int ans = -inf;
			for(int i = 0;i<=n/2;i++)
			{
				for(int j = 0;j<=n/2;j++)
				{
					ans = max(ans,dp[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i = 1;i<=n;i++)
			{
				falg[i] = 0;
			}
			for(int i = 1;i<=n;i++)
			{
				int x = read(),y = read(),z = read();
				a[++tot] = {x,x-y-z,i,1};
				a[++tot] = {y,y-x-z,i,2};
				a[++tot] = {z,z-x-y,i,3};
			}
			sort(a+1,a+1+tot,cmp);
			for(int i = 1;i<=tot;i++)
			{
				if(cnt[a[i].idd]<n/2&&(!falg[a[i].id]))
				{
					ans += a[i].vul;
					cnt[a[i].idd]++;
					falg[a[i].id] = 1;
				}
			}
			cout<<ans<<endl;
			cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
			n = tot = ans = 0;
		}
	}
	return 0;
}
