//SN-J01098  陈和骏  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int a[N],pre[2000010],dp[N];
int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=rd(),k=rd();
	for(int i=1;i<=n;i++) a[i]=rd(),a[i]^=a[i-1];
	for(int i=1;i<=(1<<20);i++) pre[i]=-1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(pre[a[i]^k]!=-1)
		{
			dp[i]=max(dp[i],dp[pre[a[i]^k]]+1);
		}
		pre[a[i]]=i;
//		for(int j=0;j<=3;j++) cout<<pre[j]<<" ";
//		cout<<"\n";
	}
	write(dp[n]);
	return 0;
}
/*
4 3
2 1 0 3
*/
