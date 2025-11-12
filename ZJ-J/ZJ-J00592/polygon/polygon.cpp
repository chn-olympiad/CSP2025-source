#include<bits/stdc++.h>
using namespace std;
long long MOD=(long long)998244353;
int inline read()
{
	int sum=0;
	char s=getchar();
	while('0'>s||s>'9')
		s=getchar();
	while('0'<=s&&s<='9')
	{
		sum=sum*10+s-'0';
		s=getchar();
	}
	return sum;
}
int a[5001],ans;
void dfs(int w,int sum,int maxa,int s)
{
	if(w+s<3)
		return ;
	if(w==0&&sum>2*maxa&&s>2)
	{
		ans++;
		ans%=MOD;
		return ;
	}
	if(w==0)
		return ;
	dfs(w-1,sum+a[w],max(maxa,a[w]),s+1);
	dfs(w-1,sum,maxa,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,maxa=0;
	n=read();
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		maxa=max(maxa,a[i]);
	}
	if(maxa==1)
	{
		long long ans=0,sum=1;
		for(i=3;i<=n;i++)
		{
			for(j=n-i+1;j<=n;j++)
				sum*=j;
			for(j=1;j<=i;j++)
				sum/=j;
			ans+=sum;
		}
		cout<<ans;
		return 0;
	}
	dfs(n,0,0,0);
	cout<<ans;
	return 0;
}
