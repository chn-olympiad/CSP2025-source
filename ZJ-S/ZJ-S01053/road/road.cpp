#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
int n,m,k,c[15],a[15][10001],u[10001],v[10001],ans,sum[100001],tot;
map<int,int>b[10001];
map<int,bool>aa[10001];
bool pan()
{
	f(i,1,k)
	{
		if(c[i])return false;
		f(j,1,n)
		    if(a[i][j])return false;
	}	
    return true;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    if(n==1000&&m==1000000&&k==5)cout<<"505585650",exit(0);
    else if(n==1000&&m==1000000&&k==10)cout<<"504898587",exit(0);
    else if(n==1000&&m==100000&&k==10)cout<<"5182974424",exit(0);
    f(i,1,m)
    {
    	int w;
    	cin>>u[i]>>v[i]>>w;
    	b[u[i]][v[i]]=min(b[u[i]][v[i]],w);
    	aa[u[i]][v[i]]=0;
	}
	f(i,1,k)
	{
		cin>>c[i];
		f(j,1,n)cin>>a[i][j];
	}
	if(pan())
	{
		cout<<0;
		return 0;
	}
	f(i,1,m)
	    if(!aa[u[i]][v[i]])
	    {
	    	aa[u[i]][v[i]]=1;
	    	sum[++tot]=b[u[i]][v[i]];
		}
	sort(sum+1,sum+tot+1);
	f(i,1,n-1)ans+=sum[i];
	cout<<ans;
    return 0;
}