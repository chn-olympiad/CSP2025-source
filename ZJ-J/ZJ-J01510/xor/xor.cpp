#include<bits/stdc++.h>
using namespace std;
int read()
{
	int val(0),f(1);
	char ch(getchar());
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		val*=10,val+=ch-'0';
		if(val<0) f=0;
		ch=getchar();
	}
	return (f==0?LONG_LONG_MAX:val);
}
struct BigInt
{
	
};
typedef long long ll;
int n;
ll a[500005],k,sum[500005];
bool flagA=true,flagB=true,flagC=true;
string str;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
//		if(a[i]>255)
//			flagA=flagB=flagC=false;
		if(a[i]>1) flagA=flagB=false;
		else if(a[i]!=1) flagA=false;
	}
	if(flagA)
	{
		if(k==1) printf("%d",n);
		else if(k==0) printf("%d",n/2);
		else printf("0");
		return 0;
	}
	if(flagB)
	{
		if(k>1||k<0) printf("0");
		else if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1) ans++;
			printf("%d",ans);
		}
		else if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==0) ans++;
				else if(a[i+1]==1)
					ans++,i++;
			printf("%d",ans);
		}
		return 0;
	}
//	if(flagC)
//	{
//		
//	}
	/*make DP and give value*/
	ll **dp=new ll*[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=new ll[n+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	/*QianZui Sum*/
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]^a[i];
	/*D-P-*/
	for(int i=1;i<=n;i++)
		for(int l=1,r=i;r<=n;l++,r++)
		{
			dp[l][r]=((sum[r]^sum[l-1])==k);
			for(int j=l;j<r;j++)
				dp[l][r]=max(dp[l][r],dp[l][j]+dp[j+1][r]);
		}
	/*D-P-2-.-0-*/
//	for(int i=1;i<=n;i++)
//		for(int l=1,r=i;r<=n;l++,r++)
//		{
//			dp[l][r]=((sum[r]^sum[l-1])==k);
//			if(i>1)
//			dp[l][r]=max(dp[l][r],
//			max(dp[l][l]+dp[l+1][r],
//			dp[l][r-1]+dp[r][r]));
//		}
	/*test*/
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d:\n",i);
//		for(int l=1,r=i;r<=n;l++,r++)
//		{
//			cout<<l<<' '<<r<<' '<<dp[l][r]<<'\n';
//		}
//		puts("");
//	}
	/*Answer Out*/
	printf("%d",dp[1][n]);
	return 0;
	/*HHHHHH I Hui Qujian DP Le*/
	/*Date FanWei is so big*/
	/*I cannot AC it*/
}
