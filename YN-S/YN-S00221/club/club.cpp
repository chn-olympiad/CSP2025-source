#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
	int d1,d2,d3;
	int maxx;
}_a[N];
int dp[N][5],a[N][5],s[4][4],_s[4][4];
// dp[i][x]表示有i个学生对x club的最大满意度
// s[i][j]表示i社团为最佳选择时,j社团的成员数量
// _s[i][j]表示上一层的s[i][j]
bool cmp(node x,node y)
{
	return x.maxx>y.maxx;
}
void ss(int x,int y)
{
	for(int i=1;i<=3;i++) s[x][i]=_s[y][i];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		bool A=1,B=1;
		int n;
		cin>>n;
		const int k=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			_a[i].d1=a[i][1];
			_a[i].d2=a[i][2];
			_a[i].d3=a[i][3];
			a[i][4]=max(max(a[i][1],a[i][2]),a[i][3]);
			_a[i].maxx=a[i][4];
			if(a[i][2]!=0) A=0;
			if(a[i][3]!=0) B=0;
		}
		sort(_a+1,_a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			a[i][1]=_a[i].d1;
			a[i][2]=_a[i].d2;
			a[i][3]=_a[i].d3;
		}
		if(A)
		{
			long long ans=0;
			for(int i=1;i<=k;i++)
				ans+=a[i][1];
			cout<<ans<<endl;
			continue;
		}
//		else if(B)
//		{
//			long long ans=0;
//			for(int i=1;i<=n;i++)
//			{
//				ans+=max(a[i][1],a[i][2]);
//			}
//			cout<<ans<<endl;
//			continue;
//		}
		for(int i=1;i<=n;i++)
		{
			bool jud=0;
			for(int j=1;j<=3;j++)
			{
				if(jud) break;
				if(dp[i-1][j]==dp[i-1][4])
				{
					int x;
					if(j==1) x=(dp[i-1][2]>dp[i-1][3])?2:3;
					else if(j==2) x=(dp[i-1][1]>dp[i-1][3])?1:3;
					else x=(dp[i-1][1]>dp[i-1][2])?1:2;
					if(_s[j][1]<k)
					{
						dp[i][1]=dp[i-1][j]+a[i][1];
						ss(1,j);
						s[1][1]++;
					}
					else if(_s[x][1]<k)
					{
						dp[i][1]=dp[i-1][x]+a[i][1];
						ss(1,x);
						s[1][1]++;
					}
					else dp[i][1]=0;
					if(_s[j][2]<k)
					{
						dp[i][2]=dp[i-1][j]+a[i][2];
						ss(2,j);
						s[2][2]++;
					}
					else if(_s[x][2]<k)
					{
						dp[i][2]=dp[i-1][x]+a[i][2];
						ss(2,x);
						s[2][2]++;
					}
					else dp[i][2]=0;
					if(_s[j][3]<k)
					{
						dp[i][3]=dp[i-1][j]+a[i][3];
						ss(3,j);
						s[3][3]++;
					}
					else if(_s[x][3]<k)
					{
						dp[i][3]=dp[i-1][x]+a[i][3];
						ss(3,x);
						s[3][3]++;
					}
					else dp[i][3]=0;
					jud=1;
				}
			}
			dp[i][4]=max(max(dp[i][1],dp[i][2]),dp[i][3]);
			for(int i=1;i<=3;i++)
				for(int j=1;j<=3;j++)
					_s[i][j]=s[i][j];
		}
		cout<<max(max(dp[n][1],dp[n][2]),dp[n][3])<<endl;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				s[i][j]=0,_s[i][j]=0;
	}
	return 0;
}
