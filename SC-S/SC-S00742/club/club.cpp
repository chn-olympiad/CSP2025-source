#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, A[100002][4], dp[202][202][202], ans=-1, B[100002], C[100002], D[100002];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--)
	{
		ll sum[4];
		sum[1]=0, sum[2]=0, sum[3]=0;
		ans=-1;
		cin>>n;
		for(int i=0; i<=n; i++)
		{
			for(int j=0; j<=n; j++)
			{
				for(int k=0; k<=n; k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
			{
				cin>>A[i][j];
				sum[j]+=A[i][j];
				if(j==1)
				{
					B[i]=A[i][j];
				}
			}
		}
		if(sum[2]==0 && sum[3]==0)
		{
			ll anss=0;
			sort(&B[1], &B[n+1]);
			for(int i=n; i>n/2; i--)
			{
				anss+=B[i];
			}
			cout<<anss<<endl;
			continue;
		}else if(sum[3]==0 && n>300)
		{
			ll anss=0;
			int nc=0, nd=0;
			for(int i=1; i<=n; i++)
			{
				anss+=max(A[i][1], A[i][2]);
				if(A[i][1] > A[i][2])
				{
					C[++nc]=A[i][1]-A[i][2];
				}else
				{
					D[++nd]=A[i][2]-A[i][1];
				}
			}
			if(nc==nd)
			{
				cout<<anss<<endl;
				continue;
			}
			if(nc>nd)
			{
				sort(&C[1], &C[nc+1]);
				ll tmp=0;
				for(int i=1; i<=nc-n/2; i++)
				{
					tmp+=C[i];
				}
				cout<<anss-tmp<<endl;
				continue;
			}
			if(nc<nd)
			{
				sort(&D[1], &D[nd+1]);
				ll tmp=0;
				for(int i=1; i<=nd-n/2; i++)
				{
					tmp+=D[i];
				}
				cout<<anss-tmp<<endl;
				continue;
			}
			
		}
		for(int i=1; i<=n; i++)
		{
			for(int j1=0; j1<=n/2; j1++)
			{
				for(int j2=0; j2<=n/2; j2++)
				{
					int j3=i-j1-j2;
					if(j3<0 || j3>n/2) continue;
					if(j1>0)
						dp[j1][j2][j3]=max(dp[j1][j2][j3], dp[j1-1][j2][j3]+A[i][1]);
					if(j2>0)
						dp[j1][j2][j3]=max(dp[j1][j2][j3], dp[j1][j2-1][j3]+A[i][2]);
					if(j3>0)
						dp[j1][j2][j3]=max(dp[j1][j2][j3], dp[j1][j2][j3-1]+A[i][3]);
					ans=max(ans, dp[j1][j2][j3]);		
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
