#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353,maxn=505;
long long n,m,k,i,j,ret,ans,flag,cnt;
long long a[maxn],b[maxn],vis[maxn],dis[maxn];
long long jie[19]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,237554682,331032489,972509923,586493473,986189864,781263551};
void dfs(long long k,long long x,long long y)
{
	if(x>=m)
	{
		ans+=jie[n-k+1];
		ans%=Mod;
		return;
	}
	if(x+(n-k)<m-1) return;
	if(k==n+1) return;
	for(long long it=1;it<=n;it++)
	{
		if(!vis[it])
		{
			vis[it]=1;
			if(y>=b[it]) dfs(k+1,x,y+1);
			else if(a[k]==1) dfs(k+1,x+1,y);
			else dfs(k+1,x,y+1);
			vis[it]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%1lld",&a[i]);
		if(a[i]==0) flag=1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		if(b[i]!=0) cnt++;
	}
	sort(b+1,b+1+n);
	if(m==n)
	{
		if(flag==1 || cnt<n)
		{
			cout<<0;
			return 0;
		}
		ans=1;
		for(i=1;i<=n;i++) ans*=i,ans%=Mod;
		printf("%lld",ans);
		return 0;
	}
	if(n<=18)
	{
		dfs(1,0,0);// dijige chenggongjige(baokuoziji) shibaijige
		printf("%lld",ans%Mod);
		return 0;
	}
	cout<<0;
	return 0;
}
//I want go to the qiguaixingweidashang!
//luogu uid：562443
//Go for it!
//Ren5Jie4Di4Ling5%
//baoliwansui!