#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
const int N=20,M=510;
const int P=998244353;

int n,m,ans,c[M],s[M];
int a[N];
bool v[N];
string tmp;

void dfs(bool vis[N],int n1,int g,int res)
{
	if(n1<=0)
	{
		if(res>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		int g1=g,cnt=res;
		vis[i]=1;
		if(c[i]<=g||s[n-n1+1]==0)g1++;
		else cnt++;
		dfs(vis,n1-1,g1,cnt);
		vis[i]=0;
	}
}

signed main()
{
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>tmp;
	for(int i=0;i<n;i++)s[i+1]=tmp[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)dfs(v,n,0,0);
	else 
	{
		int sum=0;
		for(int i=1;i<=n;i++)sum+=s[i];
		if(sum==n)
		{
			ans=1;
			while(n>1)ans*=(n--);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

