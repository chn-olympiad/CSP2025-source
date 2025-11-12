#include <bits/stdc++.h>
using namespace std;
int t,n,dp[203][203];
int f[203][103][103];int maxn=-1;
struct node
{
	int x,y,z;
}a[100003];
bool cmp(node owo,node ovo)
{return owo.x>ovo.x;}
void dfs(int u,int v,int w,int pos,int sum)
{
	if(u>n/2||v>n/2||w>n/2)
		return;
	if(pos>n)
	{
		if(sum>maxn) maxn=sum;
		return;
	}
	sum+=a[pos].x;
	dfs(u+1,v,w,pos+1,sum);
	sum-=a[pos].x;sum+=a[pos].y;
	dfs(u,v+1,w,pos+1,sum);
	sum-=a[pos].y;sum+=a[pos].z;
	dfs(u,v,w+1,pos+1,sum);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;maxn=-1;
		bool flg2=1,flg3=1;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y) flg2=0;
			if(a[i].z) flg3=0;
		}
		if(n<=10)
		{
			dfs(0,0,0,1,0);
			cout << maxn << '\n';
		}
		else if(flg2&&flg3)
		{
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=(n/2);i++)
				ans+=a[i].x;
			cout << ans << '\n';
		}
		else if(flg3)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n/2;j++)
				{
					dp[i][j]=0;
				}
			}
			dp[1][1]=a[1].x;
			dp[1][0]=a[1].y;
			dp[0][0]=0;
			for(int i=1;i<=n/2;i++)
				dp[i][0]=dp[i-1][0]+a[i].y;
			for(int i=2;i<=n;i+=2)
			{
				dp[i][i/2]=max(dp[i][i/2],max(dp[i-2][i/2-1]+a[i-1].x+a[i].y,dp[i-2][i/2-1]+a[i-1].y+a[i].x));
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=max(1,i-(n/2));j<=min(i,n/2);j++)
				{
					dp[i][j]=max(max(dp[i][j],dp[i-1][j]+a[i].y),dp[i-1][j-1]+a[i].x);
				}
			}
			cout << dp[n][n/2] << '\n';
		}
		if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n/2;j++)
				{
					for(int k=1;k<=n/2;k++)
					{
						f[i][j][k]=0;
					}
				}
			}
			f[1][0][0]=a[1].z;
			f[1][0][1]=a[1].y;
			f[1][1][0]=a[1].x;
			f[0][0][0]=0;
			for(int i=1;i<=n/2;i++)
			{
				f[i][0][0]=f[i-1][0][0]+a[i].z;
				f[i][0][i]=f[i-1][0][i-1]+a[i].y;
				f[i][i][0]=f[i-1][i-1][0]+a[i].x;
			}
				
			for(int i=2;i<=n;i+=2)
			{
				f[i][i/2][i/2]=max(f[i][i/2][i/2],max(f[i-2][i/2-1][i/2-1]+a[i-1].x+a[i].y,f[i-2][i/2-1][i/2-1]+a[i].x+a[i-1].y));
				f[i][0][i/2]=max(f[i][0][i/2],max(f[i-2][0][i/2-1]+a[i-1].y+a[i].z,f[i-2][0][i/2-1]+a[i].y+a[i-1].z));
				f[i][i/2][0]=max(f[i][i/2][0],max(f[i-2][i/2-1][0]+a[i-1].x+a[i].z,f[i-2][i/2-1][0]+a[i].x+a[i-1].z));
			}
				
			for(int i=n/2+1;i<=n;i++)
			{
				for(int j=i-(n/2);j<=(n-i+1);j++)
				{
					f[i][j][i-j]=max(f[i][j][i-j],max(f[i-1][j-1][i-j]+a[i].x,f[i-1][j][i-j-1]+a[i].y));
					f[i][0][j]=max(f[i][0][j],max(f[i-1][0][j-1]+a[i].y,f[i-1][0][j]+a[i].z));
					f[i][i-j][0]=max(f[i][i-j][0],max(f[i-1][i-j-1][0]+a[i].x,f[i-1][i-j][0]+a[i].z));
				}
					
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=min(i,n/2);j++)
				{
					for(int k=max(1,i-j-(n/2));k<=min(i,n/2)&&k+j<=i;k++)
					{
						f[i][j][k]=max(f[i][j][k],max(f[i-1][j][k]+a[i].z,max(f[i-1][j][k-1]+a[i].y,f[i-1][j-1][k]+a[i].x)));
					}
				}
			}
			for(int j=1;j<=n/2;j++)
			{
				for(int k=1;k<=n/2;k++)
				{
					if(f[n][j][k]>maxn)
						maxn=f[n][j][k];
				}
			}
			cout << maxn << '\n';
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=max(a[i].x,max(a[i].y,a[i].z));
			}
			cout << ans << '\n';
		}	
	}	
	return 0;
}
/*
1 4
4 2 0
3 2 0
5 3 0
3 5 0
*/
/*
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
//da yang li 4 yi zhi you yi ge shu ju guo bu qu
//wo dou huai yi shi *** de shu ju zao cuo le
//zhe fen dai ma yao shi na bu dao 70pts wo chi yi dun ______ 
