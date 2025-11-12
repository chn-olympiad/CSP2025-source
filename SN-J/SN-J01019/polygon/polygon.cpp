#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5010;
const int mod=998244353;

int cnt,a[N];
bool vis[N];

inline void dfs(int n,int len,int i,int lst,int sum,int mx)
{
	if(n==len&&sum>mx) {cnt=(cnt+1)%mod;return ;}
	for(int j=i;j<lst;j++)
		if(!vis[j]) vis[j]=true,dfs(n+1,len,j,lst,sum+a[j],mx),vis[j]=false;
	return ;
}

inline int ksm(int x,int y)
{
	int s=1;while(y)
	{
		if(y&1) s=s*x%mod;
		x=x*x%mod;y/=2;
	}
	return s%mod;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	bool vis1=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) vis1=false;
	}
	sort(a+1,a+n+1);
	if(n<3) {cout<<0;return 0;}
	if(n==3) {cout<<((a[1]+a[2]>a[3])? 1:0);return 0;}
	if(vis1==true) {cout<<ksm(2,n)-1-n-n*(n-1)%mod/2;return 0;}
	for(int i=3;i<=n;i++)
		for(int len=2;len<=i-1;len++)
			dfs(0,len,1,i,0,a[i]);
	cout<<cnt%mod;
	return 0;
}
