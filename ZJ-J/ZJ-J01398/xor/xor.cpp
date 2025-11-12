#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,sum,ans,ll,rr,dp[N];
int a[N];
struct wei
{
	int l,r;
}w[N];
int yi(int a,int b)
{	
	int m[33],n[33],t=0,c[33],s=0,u=0;
	memset(m,0,sizeof(m));
	memset(n,0,sizeof(n));
	memset(c,0,sizeof(c));
	while(a)
	{
	   m[++t]=a%2;
	   a/=2;	
	}	
	while(b)
	{
	   n[++u]=b%2;
	   b/=2;	
	   
	}
	for(int i=1;i<=max(u,t);i++)
	{
		if(m[i]==n[i]) c[i]=0;
		else c[i]=1;
		s+=c[i]*pow(2,i-1);
	    
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	} 
	int t=0;
	for(int i=1;i<=n;i++)
	{	
		sum=0;
		for(int j=i;j<=n;j++)
		{		   
		   sum=yi(sum,a[j]);	
		   if(sum==k) w[++t].l=i,w[t].r=j;
		} 
	} 
	for(int i=1;i<=t;i++)
	{
		dp[i]=1;
		for(int j=1;j<=i;j++)
		{
			if(w[i].l>w[j].r) dp[i]=max(dp[i],dp[j]+1);
		}
	
	} 
	cout<<dp[t];
	return 0;
}
