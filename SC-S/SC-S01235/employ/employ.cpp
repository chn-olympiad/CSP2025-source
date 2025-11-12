#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
int a[505];
int c[505];
int vis[505];
int sx[505];
long long ans=0;
void dfs(int n,int lin,int m,int lim,int nonum)
{
	if(n>lin)
	{
		//for(int i=1;i<=lin;i++) cout<<sx[i]<<' ';
		//cout<<endl;
		//cout<<m<<' '<<lim<<endl;
		if(m>=lim) ans++;
		return;
	}
	for(int i=1;i<=lin;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		sx[n]=i;
		if(nonum>=c[i] || a[n]==0) dfs(n+1,lin,m,lim,nonum+1);
		else dfs(n+1,lin,m+1,lim,nonum);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	bool isall=1;
	int isall2=0;
	for(int i=0;i<s.length();i++)
	{
		a[i+1]=s[i]-48;
		if(a[i+1]==0) isall=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) isall2++;
	}
	if(m==n && (isall2>0 ||isall==0))
	{
		cout<<0;
		return 0;
	}
	dfs(1,n,0,m,0);
	cout<<ans;
	return 0;
}