#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e5+10,M=998244353;
int n,m,a[N],vis[N],c[N];

string s;
ll ans;
void dfs(int deep)
{
	if(deep==n+1)
	{
		int t=0,k=0;
		for(int i=1;i<=n;i++)
		{
			if(t>=c[a[i]]) t++;
			else if(s[i-1]=='0') t++;
			else k++;
		}
		if(k>=m)
		{
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1,a[deep]=i;
			dfs(deep+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	
	cout<<ans;
	return 0;
}
/*
20 20
11111111111111111111
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
*/
