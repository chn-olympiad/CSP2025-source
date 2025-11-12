#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
long long int a[5005],m,ans;
bool vis[5005];
long long int YH[505][505];
inline bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)
			return true;
	}
	return false;
}
inline bool cOunt()
{
	long long int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)
		    cnt++;
	}
	if(cnt<3)
	    return true;
	else
	    return false;
}
inline long long int maxn()
{
	long long int ansn=LLONG_MIN;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			ansn=max(ansn,a[i]);
		}
	}
	return ansn;
}
inline void up()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=!vis[i];
		if(vis[i])
		    break;
	}
	return ;
}
inline long long int ccc()
{
	long long int adddd=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			adddd+=a[i];
		}
	}
	if(adddd>2*maxn())
	    return 1;
	else
	    return 0;
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
		vis[3]=vis[2]=vis[1]=true;
		while(check())
		{
			if(cOunt())
			{
				up();
				continue;
			}
			ans+=ccc();
			ans%=mod;
			up();
		}
		cout<<ans<<"\n";
	}
	return 0;
}