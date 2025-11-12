#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+7;
int t,n;
int l,h,z;
long long a[N][3];
long long dp[N][3];//f[i][j]表示第i个人在j时的最大值 
int sum[N][3];
long long ans=0;
bool cmp(int x,int y)
{
	return x>y;
}
//void ans2()
//{
//	long long ans=0;
//	for(int i=1;i<=3;i++)
//	{
//		for(int j=1;j<=3;j++)
//		{
//			if(i==j)continue;
//			ans=max(a[1][i]+a[2][j],ans);
//		 } 
//	}
//	cout<<ans<<'\n';
//}
void ansA(int li)
{
	long long a2[N];
	for(int i=1;i<=n;i++)
	{
		a2[i]=a[i][2];
	}
	long long ans=0;
	sort(a2+1,a2+1+n,cmp);
	for(int i=1;i<=li;i++)
	{
		ans+=a2[i];
	}
	cout<<ans<<'\n';
}
void dfs(int x,int sum1,int sum2,int sum3,long long v)
{
	if(x==n)
	{
		ans=max(ans,v);
		return;
	}
	x++;
	int li=n>>1;
	if(sum1+1<=li)
	{
		v+=a[x][1];
		sum1++;
		dfs(x,sum1,sum2,sum3,v);
		sum1--;
		v-=a[x][1];
	}
	if(sum2+1<=li)
	{
		v+=a[x][2];
		sum2++;
		dfs(x,sum1,sum2,sum3,v);
		sum2--;
		v-=a[x][2];
	}
	if(sum3+1<=li)
	{
		v+=a[x][3];
		sum3++;
		dfs(x,sum1,sum2,sum3,v);
		sum3--;
		v-=a[x][3];
	}
}
void slove()
{
	cin>>n;
	ans=0;
	int li=(n>>1);
	int cnr=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>h>>z;
		if(l==0&&z==0)cnr++;
		if(z==0)cnt++;
		a[i][1]=l;a[i][2]=h;a[i][3]=z;
	}
//	if(n==2)
//	{
//		ans2();
//		return;
//	}
	if(cnr==n)
	{
		ansA(li);
		return;
	}
	if(n<=200)
	{
		dfs(1,1,0,0,a[1][1]);
		dfs(1,0,1,0,a[1][2]);
		dfs(1,0,0,1,a[1][3]);
		cout<<ans<<'\n';
		return;
	}
	dp[1][1]=a[1][1];
	dp[1][2]=a[1][2];
	dp[1][3]=a[1][3];
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=max(dp[i-1][1]+a[i][1],max(dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]));
		dp[i][2]=max(dp[i-1][1]+a[i][2],max(dp[i-1][2]+a[i][2],dp[i-1][3]+a[i][2]));
		dp[i][3]=max(dp[i-1][1]+a[i][3],max(dp[i-1][2]+a[i][3],dp[i-1][3]+a[i][3]));
	}
	ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
	cout<<ans<<'\n';
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		slove();
	}
	return 0;
}
/*
t-5
n-2e5
aij-2e4

[ 不多于 n/2 ]<=>[ <=(n>>1) ]

数据保障不存在负数

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0  
*/
