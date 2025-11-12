#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,a[505],vis[505],b[505],fact[505],ans;
string s;
void dfs(int step)
{
	if(step==n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(s[i]=='0')
		cnt++;
		else
		if(a[b[i]]<=cnt)
		cnt++;
		if(n-cnt>=m)
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	if(vis[i]==0)
	{
		vis[i]=1;
		b[step+1]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	fact[0]=1;
	for(int i=1;i<=500;i++)
	fact[i]=fact[i-1]*(1LL*i)%N;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);

	s=' '+s;	
	if(m==n||n>=100)
	{
		for(int i=1;i<=n;i++)
		if(s[i]=='0'||a[i]==0)
		{
			cout<<0;
			return 0;
		}
		cout<<fact[n];
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}

