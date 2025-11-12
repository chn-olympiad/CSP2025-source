#include<bits/stdc++.h>

using namespace std;
int z[4],n;
struct C
{
	int a[4];
	bool operator < (const C& o) const{
		if(a[z[1]]==o.a[z[1]])
		{
			if(a[z[2]]==o.a[z[2]])
			{
				return a[z[3]]>o.a[z[3]];
			}
			return a[z[2]]>o.a[z[2]];
		}
		return a[z[1]]>o.a[z[1]];
	}
}c[100001];
bool cmp(pair<int,int>a, pair<int,int>b) {return a.first>b.first;}
int dp[100001][4];// 第i个员工选第j个部门的最大满意度。
int num[100001][4][4];// 第i个员工选第j个部门满意度最大时第k个部门的人数
int dfsans=0;
void dfs(int num, int an, int bn, int cn, int p)
{
	if (p>n) 
	{
		dfsans=max(dfsans,num);
		return;
	}
	if(an<n/2) dfs(num+c[p].a[1],an+1,bn,cn,p+1);
	if(bn<n/2) dfs(num+c[p].a[2],an,bn+1,cn,p+1);
	if(cn<n/2) dfs(num+c[p].a[3],an,bn,cn+1,p+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(dp,0,sizeof dp);
		memset(num,0,sizeof num);
		pair<int,int> sum[4];
		for(int i=1;i<=3;i++)
		{
			sum[i].first=0;
			sum[i].second=i;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>c[i].a[1]>>c[i].a[2]>>c[i].a[3];
			sum[1].first+=c[i].a[1];
			sum[2].first+=c[i].a[2];
			sum[3].first+=c[i].a[3];
		}
		if(n<20)
		{
			dfsans=0;
			dfs(0,0,0,0,1);
			cout<<dfsans<<endl;
			continue;
		}
		sort(sum+1,sum+4,cmp);
		for(int i=1;i<=3;i++) z[i]=sum[i].second;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
		{
//			for(int j=1;j<=3;j++){
//				for(int k=1;k<=3;k++){
//					num[i][j][k]=num[i-1][j][k];
//				}
//			}
			for(int j=1;j<=3;j++) //这一个员工选的
			{
				int mx;
				for(int k=1;k<=3;k++) // 上一个员工选的
				{
					if(num[i-1][k][j]<n/2)
					{
						if(dp[i-1][k]+c[i].a[j]>dp[i][j])
						{
							dp[i][j]=dp[i-1][k]+c[i].a[j];
							mx=k;
							//cout<<"Choose "<<j<<" at "<<i<<endl;
						}
					}
				}
				for(int k=1;k<=3;k++)
				{
					num[i][j][k]=num[i-1][mx][k];
				}
				num[i][j][j]=num[i-1][mx][j]+1;
				//cout<<dp[i][j]<<' ';
			}			
//			cout<<endl;
//			for(int j=1;j<=3;j++)
//			{
//				for(int k=1;k<=3;k++)
//				{
//					cout<<num[i][j][k]<<' ';
//				}
//				cout<<endl;
//			}
//			cout<<endl;
		}
		
		cout<<max(max(dp[n][1],dp[n][2]),max(dp[n][1],dp[n][3]))<<endl;
	}
	
	return 0;
}
/*
1
8
10 50 80
40 20 90
30 50 60
80 20 80
60 30 50
90 10 20
20 10 90
40 40 90

630
*/