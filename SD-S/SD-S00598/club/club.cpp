#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005][3];


void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	if(n<=30)
	{
		int dp[35][35][35]={0},ans=0;
		dp[1][1][0]=a[1][0]; dp[1][0][1]=a[1][1]; dp[1][0][0]=a[1][2];
		for(int i=2;i<=n;i++)
		{
			for(int cl0=0;cl0<=(n/2)&&cl0<=i;cl0++)
			{
				for(int cl1=0;cl1<=(n/2)&&cl1<=i;cl1++)
				{
					int cl2=i-cl0-cl1;
					if(cl2<0) continue;
					if(cl2>(n/2)) continue;
					if(cl2-1>=0)
						dp[i][cl0][cl1]=max(dp[i][cl0][cl1],dp[i-1][cl0  ][cl1  ]+a[i][2]);
					if(cl1-1>=0)
						dp[i][cl0][cl1]=max(dp[i][cl0][cl1],dp[i-1][cl0  ][cl1-1]+a[i][1]);
					if(cl0-1>=0)
						dp[i][cl0][cl1]=max(dp[i][cl0][cl1],dp[i-1][cl0-1][cl1  ]+a[i][0]);
					
						
					ans=max(ans,dp[i][cl0][cl1]);
					
					//cout<<i<<" "<<cl0<<cl1<<cl2<<" "<<dp[cl0][cl1]<<"\n"; 
				}
			}
		}
		cout<<ans<<"\n";
	}
	else //A
	{
		int f[100005]={0},ans=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=a[i][0];
		}
		sort(f+1,f+1+n,greater<int>());
		for(int i=1;i<=(n/2);i++)
		{
			ans+=f[i];	
		}
		cout<<ans<<"\n";
	}
	
}

int main()
{
 	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
