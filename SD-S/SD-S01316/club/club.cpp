#include<bits/stdc++.h>
#define inf LLONG_MAX
using namespace std;
typedef long long ll;
typedef __int128 llong;
const ll N=2e1+5;
ll t,n,y[N][4],ans;
void dfs(ll k,ll a,ll b,ll c,ll tot)
{
	if(k==n+1)
	{
		ans=max(ans,tot);
	}
	if(a+1<=n/2)
	{
		dfs(k+1,a+1,b,c,tot+y[k][1]);
	}
	if(b+1<=n/2)
	{
		dfs(k+1,a,b+1,c,tot+y[k][2]);
	}
	if(c+1<=n/2)
	{
		dfs(k+1,a,b,c+1,tot+y[k][3]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	ans=0;
    	cin>>n;
	    for(int i=1;i<=n;i++)
	    {
	   		for(int j=1;j<=3;j++)
	   		{
	   			cin>>y[i][j];	
			}
	    }
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}	
