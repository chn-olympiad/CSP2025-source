#include<bits/stdc++.h>
using namespace std;
#define int long long
bool startmb;
constexpr int N=505,mod=998244353;
int n,m,a[N];
char s[N];

namespace solve1
{
	bool check(){return n<=18;}
	int dp[(1<<18)+5][20][20];
	int Mod(int x){return x-(x>=mod)*mod;}
	void solve()
	{
		dp[0][0][0]=1;
		for(int s=0;s<1<<n;s++)
		{
			for(int i=0;i<n;i++)
			{
				if(!((s>>i)&1))
				{
					int p=__builtin_popcount(s);
					for(int j=0;j<=p;j++)
					{
						for(int k=0;j+k<=p;k++)
						{
							if(::s[p+1]=='0') dp[s|(1<<i)][j+1][k]=Mod(dp[s][j][k]+dp[s|(1<<i)][j+1][k]);
							else
							{
								if(a[i+1]<=j)
								{
									dp[s|(1<<i)][j+1][k]=Mod(dp[s][j][k]+dp[s|(1<<i)][j+1][k]);
								}
								else
								{
									dp[s|(1<<i)][j][k+1]=Mod(dp[s][j][k]+dp[s|(1<<i)][j][k+1]);
								}
							}
						}
					}
				}
			}
		}
//		cout<<dp[3][1][1]<<endl;
//		cout<<dp[7][0][2]<<endl;
		int ans=0;
		for(int j=0;j<=n;j++) for(int i=m;i<=n;i++) ans=Mod(ans+dp[(1<<n)-1][j][i]);
		cout<<ans;
	}
}
namespace solve2
{
	bool check(){return m==1;}
	int cnt[N];
	void solve()
	{
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		int num=1,tot=0,sum=n;
		for(int i=1;i<=n;i++)
		{
			tot+=cnt[i-1];
			if(s[i]=='1') num=num*tot%mod,tot--,sum--;
		}
		for(int i=1;i<=sum;i++) num=num*i%mod;
		cout<<(ans-num+mod)%mod;
	}
}
namespace solve3
{
	bool check(){return m==n;}
	void solve()
	{
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		for(int i=1;i<=n;i++) if(s[i]=='0'||a[i]==0) cout<<0,exit(0);
		cout<<ans;
	}
}

bool endmb;
main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cerr<<((&endmb-&startmb)/1024.0/1024)<<'\n';
	cin.tie(0)->sync_with_stdio(false);
	double starttime=clock();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(solve1::check()) solve1::solve();
	else if(solve2::check()) solve2::solve();
	else if(solve3::check()) solve3::solve();
	cerr<<((clock()-starttime)/CLOCKS_PER_SEC)<<'\n';
	return 0;
}
//多测要清空
//测极端数据
//注意数组大小
//注意保留小数位数

