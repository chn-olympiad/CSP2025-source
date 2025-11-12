#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
#define mod 998244353
using namespace std;
int n,a[5001],qpl[5001],dp[5001][5001],ans;
bool pan()
{
	f(i,1,n)
	    if(a[i]!=1)return false;
	return true;
}
void dfs(int pos,int sum,int k)
{
	if(sum>k*2)(ans+=1)%=mod;
	if(pos>n)return;
	f(i,pos,n)
	    dfs(i+1,sum+a[i],max(k,a[i]));
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	f(i,1,n)cin>>a[i];
	if(pan())
	{
		int sum=1,o=1;
		f(i,3,n)
		{
		    d(j,n,n-i+1)
		    {
		    	(sum*=j)%=mod,(sum/=o)%=mod;
		    	if(o<i)++o;
			}	
			(ans+=sum)%=mod;		
		}
		cout<<ans;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
