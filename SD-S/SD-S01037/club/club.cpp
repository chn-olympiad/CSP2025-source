#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll qr()
{
	ll flag=1,sum=0;
	char ch=getchar();
	for(;!isdigit(ch);flag=(ch=='-')?-1:1,ch=getchar());
	for(;isdigit(ch);sum=sum*10+ch-'0',ch=getchar());
	return flag * sum;
}
inline ll mx(ll x,ll y)
{
	return x>y ? x:y;
}
struct node{
	ll x,y,z;
}a[1000002];
ll dp[202][202][202];
ll n,t,ans;
bool chk2;
bool cmp1(node x,node y)
{
	if(x.x<y.x)  return 0;
}
int main()
{
	ll i,j,ii;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=qr();
	while(t--)
	{
		chk2=0;
		ans=0;memset(dp,0,sizeof(dp));
		n=qr();
		if(n<=210)  chk2=1;
		for(i=1;i<=n;i++)
		{
			a[i].x=qr(),a[i].y=qr(),a[i].z=qr();
		}
		if(chk2)
		{	
			for(i=0;i<n;i++)
			{
				ll k=min(i,n/2);
				for(j=0;j<=k;j++)
				{
					for(ii=0;ii<=k&&ii<=i-j;ii++)
					{
						
//						dp[j][ii][i-j-ii]=mx(mx(mx(dp[j-1][ii][i-j-ii]+a[i].x,dp[j][ii-1][i-j-ii]+a[i].y),dp[j][ii][i-j-ii-1]+a[i].z),dp[j][ii][i-j-ii]);
//						if(dp[j][ii][i-j-ii]>ans)ans=mx(ans,dp[j][ii][i-j-ii]),cout<<j<<" "<<ii<<" "<<i-j-ii<<endl;
						ll jj=(i-j-ii);
						if(jj>k)  continue;
						if((j+1)<=n/2&&(j+1)<=(i+1))	dp[j+1][ii][jj]=mx(dp[j+1][ii][jj],dp[j][ii][jj]+a[i+1].x),ans=mx(ans,dp[j+1][ii][jj]);
						if((ii+1)<=n/2&&(ii+1)<=(i+1))	dp[j][ii+1][jj]=mx(dp[j][ii+1][jj],dp[j][ii][jj]+a[i+1].y),ans=mx(ans,dp[j][ii+1][jj]);
						if((jj+1)<=n/2&&(jj+1)<=(i+1))	dp[j][ii][jj+1]=mx(dp[j][ii][jj+1],dp[j][ii][jj]+a[i+1].z),ans=mx(ans,dp[j][ii][jj+1]);
						
					}
				}
			}
			cout<<ans<<"\n";
		}
		else
		{
			sort(a+1,a+1+n,cmp1);
			for(i=1;i<=n/2;i++)  ans+=a[i].x;
			cout<<ans<<"\n";
		}
	}
	return 0;

}
