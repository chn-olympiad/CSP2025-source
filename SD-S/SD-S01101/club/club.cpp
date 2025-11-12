#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++) 
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int N=1e3+5;
ll n,ans,f[2][N][N],dp[2][N],tea;
struct node{
	ll a,b,c;
}t[N];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
void solve()
{
	cin>>n;
	For(i,1,n)
	{
		cin>>t[i].a>>t[i].b>>t[i].c;
		if(t[i].b==0&&t[i].c==0)tea++;
	}
	if(n<=200)
	{
		For(i,0,n)For(j,0,n)f[1][i][j]=f[0][i][j]=0;
		f[1][1][0]=t[1].a;
		f[1][0][1]=t[1].b;
		f[1][0][0]=t[1].c;
		For(i,2,n)
		{
			For(j,0,i)
			{
				For(k,0,i)
				{
					int l=i-j-k;
					if(l<0)break;
					if(j>n/2)break;
					if(k>n/2)break;
					if(j==0&&k==0)f[i&1][j][k]=f[(i-1)&1][j][k]+t[i].c;
					else if(j==0)f[i&1][j][k]=max(f[(i-1)&1][j][k-1]+t[i].b,f[(i-1)&1][j][k]+t[i].c);
					else if(k==0)f[i&1][j][k]=max(f[(i-1)&1][j-1][k]+t[i].a,f[(i-1)&1][j][k]+t[i].c);
					else f[i&1][j][k]=max(f[(i-1)&1][j-1][k]+t[i].a,max(f[(i-1)&1][j][k-1]+t[i].b,f[(i-1)&1][j][k]+t[i].c));
				}
			}
		}
		ans=0;
		For(i,0,n/2)
		{
			For(j,0,n/2)
			{
				int l=n-i-j;
				if(l>n/2)continue;
				ans=max(ans,f[0][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		ans=0;
		if(tea==n)
		{
			sort(t+1,t+1+n,cmp);
			For(i,1,n/2)ans+=t[i].a;
			cout<<ans<<endl;
		}
		else
		{
			For(i,1,0)dp[0][i]=dp[1][i]=0;
			dp[1][1]=t[1].a;
			dp[1][0]=t[1].b;
			For(i,2,n)
			{
				For(j,0,i)
				{
					if(j>n/2)break;
					if(j==0)dp[i&1][j]=dp[(i-1)&1][j]+t[i].b;
					else if(j==i)dp[i&1][j]=dp[(i-1)&1][j-1]+t[i].a;
					else dp[i&1][j]=max(dp[(i-1)&1][j]+t[i].b,dp[(i-1)&1][j-1]+t[i].a);
				}
			}
			cout<<dp[0][n/2]<<endl;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
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
