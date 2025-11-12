#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int T;
int n,m,cnt,k[N][5][5],a[N][5],maxn,maxk;
ll MAXN,dp[N][5];
struct node{
	int x,y,z,tot,maxn;
}A[N];
bool cmp1(node N,node M)
{
	return N.maxn>M.maxn;
}
bool cmp2(node N,node M)
{
	return N.maxn<M.maxn;
}
ll ado()
{
	for(int i=1;i<=3;++i)
	{
		dp[1][i]=a[1][i]*1ll;
		k[1][i][i]=1;
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=3;++j)
		{
			cnt=0;
			for(int l=1;l<=3;++l)
			{
				if(k[i-1][l][j]+1<=m)
				{
					if(dp[i-1][l]+a[i][j]>dp[i][j])
					{
						dp[i][j]=dp[i-1][l]+a[i][j];
						cnt=l;
					}
				}
			}
			for(int l=1;l<=3;++l)
				k[i][j][l]=k[i-1][j][l];
			++k[i][j][cnt];
		}
	}
	return max(dp[n][1],max(dp[n][2],dp[n][3]));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		m=n/2;
		memset(dp,0,sizeof dp);
		memset(k,0,sizeof k);
		MAXN=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			A[i].x=a[i][1];
			A[i].y=a[i][2];
			A[i].z=a[i][3];
			A[i].tot=a[i][1]+a[i][2]+a[i][3];
			A[i].maxn=max(a[i][1],max(a[i][2],a[i][3]));
		}
		sort(A+1,A+n+1,cmp1);
		for(int i=1;i<=n;++i)
		{
			a[i][1]=A[i].x;
			a[i][2]=A[i].y;
			a[i][3]=A[i].z;
		}
		MAXN=max(MAXN,ado());
		memset(dp,0,sizeof dp);
		memset(k,0,sizeof k);
		sort(A+1,A+n+1,cmp2);
		for(int i=1;i<=n;++i)
		{
			a[i][1]=A[i].x;
			a[i][2]=A[i].y;
			a[i][3]=A[i].z;
		}
		printf("%lld\n",max(MAXN,ado()));
	}
	return 0;
}
