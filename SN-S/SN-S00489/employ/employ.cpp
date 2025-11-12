#include<bits/stdc++.h>
using namespace std;
int n,m;
string str;
int c[505];
bool vis[505];
long long sum=0;
void dfs(int x,int s,int f)
{
	if(x==n-1)
	{
		if(s>=m)
			sum++;
		sum%=998244353;
		return;
	}
	for(int i=0;i<n;i++)
	{
		int js=0,jf=0;
		if(vis[i])
			continue;
		vis[i]=true;
		if(str[x]=='1'&&f<c[i])
			js++;
		else
			jf++;
		dfs(x+1,s+js,f+jf);
		vis[i]=false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<n;i++)
		cin>>c[i];
	dfs(0,0,0);
	printf("%lld",sum%998244353);
	return 0;
}

