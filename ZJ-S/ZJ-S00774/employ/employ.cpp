#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int MOD=998244353;
int n,m,a[N];
long long ans,wh;
bool vis[N];
string s;
void dfs(int k,int los)
{
	if(k==n)
	{
		if(n-los>=m)
		{
			ans=(ans+1)%MOD;
		}
		return ;
	}
	if(n-los<m)
		return;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(los>=a[i])
			{
				dfs(k+1,los+1);
			}
			else
			{
				if(s[k]=='0')
				{
					dfs(k+1,los+1);
				}
				else
				{
					dfs(k+1,los);
				}
			}
			vis[i]=0;
		}
	}
}
bool check()
{
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
			return 0;
	}
	return 1;
}
void aw2()
{
	long long sum=1;
	for(int i=1;i<m;i++)
	{
		sum=(sum*(n-i+1))%MOD;
	}
	for(int i=m;i<=n;i++)
	{
		sum=(sum*(n-i+1))%MOD;
		ans=(ans+sum)%MOD;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			wh++;
		}
	}
//	if(check())
//	{
//		n-=wh;
//		aw2();
//	}
//	else
//	{
	dfs(0,0);	
//	}
	printf("%lld",ans);
	return 0;
}
