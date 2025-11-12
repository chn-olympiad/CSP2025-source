#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=205;
const int inf=1e9+7;
int n;
int a[MAXN][10];
int dp[MAXN][MAXN][MAXN];
void Max(int &a,int b)
{
	if(b>a) a=b;
}

void solve()
{
	
	cin>>n;
	
	bool flagA=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) 
		{
			cin>>a[i][j];
		}
		if(a[i][2]!=0) flagA=0;
		if(a[i][3]!=0) flagA=0;
	}
	
	if(flagA==1)
	{
		vector<int> ve;
		for(int i=1;i<=n;i++) ve.push_back(a[i][1]);
		sort(ve.begin(),ve.end(),[](int a,int b)
		{
			return a>b;
		});
		int ans=0;
		for(int i=0;i<n/2;i++) ans+=ve[i];
		cout<<ans<<endl;
		return ;
	}
	
	
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) dp[i][j][k]=-inf;
	dp[0][0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=i;k++)
			{
				int p=i-j-k;
				if(p>i) continue;
				if(p<0) continue;
				int now=dp[j][k][p];
				Max(dp[j+1][k][p],now+a[i+1][1]);
				Max(dp[j][k+1][p],now+a[i+1][2]);
				Max(dp[j][k][p+1],now+a[i+1][3]);
			}
		}
	}
	
	int ans=0;
	for(int j=0;j<=n/2;j++)
	{
		for(int k=0;k<=n/2;k++)
		{
			int p=n-j-k;
			if(p>n/2) continue;
			int now=dp[j][k][p];
			Max(ans,now);
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ttt; for(cin>>ttt;ttt--;)
	solve();
	return 0;
}

/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0


10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

2211746

*/
