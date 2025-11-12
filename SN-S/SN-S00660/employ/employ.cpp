#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int mod=998244353;

int n,m,ans=0;
string s;
int a[MAXN],w[MAXN];
bool vis[MAXN];

void dfs(int u)
{
	if(u>n)
	{
		int f=0,t=0;
		for(int i=1;i<=n;i++)
		{
			if(f>=w[i])
			{
				f++;
				continue;
			}
			if(s[i-1]=='0') f++;
			else t++;
		} 
		if(t>=m) 
		{
			ans++;
//			for(int i=1;i<=n;i++) cout<<w[i]<<' ';
//			cout<<endl;
		}
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	if(vis[i]==0)
	{
		w[u]=a[i];
		vis[i]=1;
		dfs(u+1);
		vis[i]=0;
	}
}


bool flagA=1;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>s;
	for(char c:s) flagA&=(c=='1');
	for(int i=1;i<=n;i++) cin>>a[i];

	
	
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
