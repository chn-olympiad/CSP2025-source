#include<bits/stdc++.h>
using namespace std;
int n,k,aa[25],b[25],c[25];
long long a[1005],f[1005][1005],sum,ans,res,cnt,cmt,dp[1005],q=1;
int xx(int u,int v)
{
	if(u==v) return 0;
	memset(aa,-1,sizeof(aa));
	memset(b,-1,sizeof(b));
	memset(c,-1,sizeof(c));
	cnt=cmt=sum=0;
    while(u>0)
	{
		a[++cnt]=u%2;
		u/=2;
	}
	while(v>0)
	{
		b[++cmt]=v%2;
		v/=2;
	}
	int sum=0;
	int s=1,t=1;
	while(s<=cnt||t<=cmt)
	{
		if(s>cnt){
			for(int i=cnt+1;i<=cmt;i++) c[i]=1;
			sum=cmt;
			break;
		}
		else if(t>cmt){
			for(int i=cmt+1;i<=cnt;i++) c[i]=1;
			sum=cnt;
			break;
		}
		if(a[s]==b[t]) c[++sum]=0;
		else c[++sum]=1;
		s++;
		t++;
	}
	q=1;
	long long xyh=0;
	for(int i=1;i<=sum;i++)
	{
		xyh+=q*c[i];
		q*=2;
	}
	return xyh;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	  for(int j=i;j<=n;j++)
	  {
	  	if(i==j) f[i][j]=a[i];
	  	else f[i][j]=xx(f[i][j-1],a[j]);
	  }
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(f[j][i]==k)
	  	  dp[i]=max(dp[i],dp[j-1]+1);
	  }
	cout<<dp[n];
	return 0;
}
