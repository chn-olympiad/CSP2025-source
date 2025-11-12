#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
#define mod 998244353
using namespace std;
int n,m,c[501],ans,vis[501],d[501],ss,add[501],abc=1;
char s[501];
void dfs(int pos) 
{
	if(pos==n)
	{
		int pass=0;
		f(i,1,n)
		    if(i-1-pass<c[d[i]]&&s[i]=='1')pass++;
		if(pass>=m)(ans+=1)%=mod;
		return;
	}
	f(i,1,n)
	    if(!vis[i])
	    {
	    	vis[i]=1;
	    	d[pos+1]=i;
	    	dfs(pos+1);
	    	vis[i]=0;
		}
}
void dfs2(int pos)
{
	if(pos==ss)
	{
		int pass=0;
		f(i,1,ss)
		    if(add[i]-1-pass<c[d[i]])pass++;
		if(pass>=m)(ans+=abc)%=mod;
		return;
	}
	f(i,1,n)
	    if(!vis[i])
	    {
	    	vis[i]=1;
	    	d[pos+1]=i;
	    	dfs(pos+1);
	    	vis[i]=0;
		}
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    string abcd;
    cin>>abcd;
    f(i,0,n-1)s[i]=abcd[i+1];
    f(i,1,n)cin>>c[i];
    if(m==n)
    {
    	f(i,1,n)
    	    if(s[i]=='0'||!c[i])
    	    {
    	    	cout<<0;
    	    	return 0;
			}
		dfs(0);
		cout<<ans;
		return 0;
	}
	if(n<=18)
	{
		dfs(0);
		cout<<ans;
		return 0;
	}
	f(i,1,n)
	    if(s[i]=='1')add[++ss]=i;
	f(i,1,n-ss+1)(abc*=i)%=mod;
	if(ss<=18)
	{
		dfs2(0);
		cout<<ans;
		return 0;
	}
    return 0;
}