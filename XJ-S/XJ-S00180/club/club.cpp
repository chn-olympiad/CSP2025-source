#include<iostream> 
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e5+5;
struct node
{
	int v,c[5];
};
struct node2
{
	int p,ma;
};
int f[105][105][105];
int a[N][5],aa[N][5],n;
node dp[N][5];
node2 b[N];
bool cmp(node x,node y)
{
	return x.v<y.v;
}
bool cmpp(node2 x,node2 y)
{
	return x.ma>y.ma;
}
int dfs(int c1,int c2,int c3)
{
	if(f[c1][c2][c3]) return f[c1][c2][c3];
	int p=c1+c2+c3;
	if(p==n+1)
	{
		return 0;
	}
	int ans=0;
	if(c1+1<=n/2) ans=max(ans,a[p][1]+dfs(c1+1,c2,c3));
	if(c2+1<=n/2) ans=max(ans,a[p][2]+dfs(c1,c2+1,c3));
	if(c3+1<=n/2) ans=max(ans,a[p][3]+dfs(c1,c2,c3+1));
	return f[c1][c2][c3]=ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,i,j,k;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof dp);
		int maxx=0;
		cin>>n;
		if(n<=205)
		{
			memset(f,0,sizeof f);
			for(i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
			cout<<dfs(0,0,0)<<endl;
			continue;
		}
		for(i=1;i<=n;i++)
		{
			cin>>aa[i][1]>>aa[i][2]>>aa[i][3];
			b[i]={i,max(max(aa[i][1],aa[i][2]),aa[i][3])};
		}
		sort(b+1,b+n+1,cmpp);
		for(i=1;i<=n;i++)
		{
			a[i][1]=aa[b[i].p][1];
			a[i][2]=aa[b[i].p][2];
			a[i][3]=aa[b[i].p][3];
		}
		for(i=1;i<=n;i++)
		{
			node t[6];
			for(j=1;j<=3;j++)
			{
				t[j].v=dp[i-1][j].v;
				t[j].c[1]=dp[i-1][j].c[1];
				t[j].c[2]=dp[i-1][j].c[2];
				t[j].c[3]=dp[i-1][j].c[3];
			}
			sort(t+1,t+4,cmp);
			for(j=1;j<=3;j++)
			{
				for(k=1;k<=3;k++)
				{
					if(t[k].c[j]>=n/2) continue;
					dp[i][j].v=t[k].v;
					dp[i][j].c[1]=t[k].c[1];
					dp[i][j].c[2]=t[k].c[2];
					dp[i][j].c[3]=t[k].c[3];
				}
				dp[i][j].v+=a[i][j];
				dp[i][j].c[j]++;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++) maxx=max(maxx,dp[i][j].v);
		}
		cout<<maxx<<endl;
	}
	return 0;
}
