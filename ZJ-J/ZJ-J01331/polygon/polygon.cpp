#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
long long int a[5005],m,ans;
long long int YH[5005][5005];
long long int q[5005],KSM[5005];
bool cmp(long long int A,long long int B)
{
	return A>B;
}
inline void dfs(long long int maxn,long long int lst,long long int sum)
{
	if(sum+q[n]-q[lst]<=maxn)
	{
		return ;
	}
	if(sum>maxn)
	{
		ans+=KSM[n-lst];
		ans%=mod;
		return ;
	}
	for(int i=lst+1;i<=n;i++)
	{
		dfs(maxn,i,sum+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
		m=max(m,a[i]);
	}
	if(m==1)
	{
		YH[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j==0)
					YH[i][0]=1;
				else
					YH[i][j]=YH[i-1][j-1]+YH[i-1][j];
				YH[i][j]%=mod;
			}
		}
		for(int i=3;i<=n;i++)
		{
			ans+=YH[n][i];
			ans%=mod;
		}
		cout<<ans<<"\n";
	}
	else
	{
		sort(a+1,a+1+n,cmp);
		KSM[0]=1;
		for(int i=1;i<=n;i++)
		{
		    KSM[i]=(KSM[i-1]*2)%mod;
			q[i]=q[i-1]+a[i];
		}
		for(int i=1;i<=n-2;i++)
		{
			dfs(a[i],i,0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}