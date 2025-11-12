#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1,maxm=201,maxmm=5e4+1;
int a[maxn][4];
int dp[maxm][maxm][maxm];
int sor[maxn];
int n;
bool sp()
{
	bool fA=1,fB=1;
	int lim=n/2;
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]!=0)
		{
			fA=0;
		}
		if(a[i][3]!=0)
		{
			fB=0;
			break;
		}
		sor[i]=a[i][1];
	}
	if(fB==0)
	{
		return 0;
	}
	if(fA&&fB)
	{
		sort(sor+1,sor+n+1);
		int ans=0;
		for(int i=n;i>n/2;i--)
		{
			ans+=sor[i];
		}
		cout<<ans<<"\n";
		return 1;
	}
	else if(fB)
	{
		if(lim>maxm)
		{
			int ans=0;
			int n1=0,n2=0;
			for(int i=1;i<=n;i++)
			{
				if(n1>=lim)
				{
					n2++;
					ans+=a[i][2];
				}
				else if(n2>=lim)
				{
					n1++;
					ans+=a[i][1];
				}
				else 
				{
					if(a[i][1]>a[i][2])
					{
						n1++;
						ans+=a[i][1];
					}
					else
					{
						n2++;
						ans+=a[i][2];
					}
				}
			}
			cout<<ans<<"\n";
			return 1;
		}
	} 
	return 0;
}
void init(int n)
{
	memset(dp,0,sizeof(dp));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		init(n);
		int lim=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		if(sp())
		{
			continue;
		}
		int ans=0;
		for(int i=0;i<=lim;i++)
		{
			for(int j=0;j<=lim;j++)
			{
				for(int k=0;k<=lim;k++)
				{
					int id=i+j+k+1;
					if(id>n)
					{
						break;	
					}	
					if(i+1<=lim)
					{
						dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[id][1]);
						ans=max(ans,dp[i+1][j][k]);
					}
					if(j+1<=lim)
					{
						dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a[id][2]);
						ans=max(ans,dp[i][j+1][k]);
					}
					if(k+1<=lim)
					{
						dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a[id][3]);
						ans=max(ans,dp[i][j][k+1]);
					}
				}	
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;	
} 

