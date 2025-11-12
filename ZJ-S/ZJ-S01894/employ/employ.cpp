#include<bits/stdc++.h>
using namespace std;
long long mn=501,n,m,k,s,ans,c[501],a[501],M=998244353;
bool b[501];
string S;
void dfs(long long id)
{
	if(id>n)
	{
		k=0,s=0;
		for(long long i=1;i<=n;++i)
		  if(S[i-1]=='0'||k>=c[i])
		    ++k;else
		    ++s;
		if(s>=m)
		  ++ans;
		return;
	}
	for(long long i=1;i<=n;++i)
	  if(!b[i])
	  {
	  	b[i]=true;
	  	c[id]=-a[i];
	  	dfs(id+1);
	  	b[i]=false;
	  }
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>S;
	for(long long i=1;i<=n;++i)
	  cin>>a[i],mn=min(mn,a[i]),a[i]=-a[i];
	sort(a+1,a+1+n);
	if(S.find('0')==-1)
	{
		if(m!=n||!mn)
		{
			cout<<"0";
			return 0;
		}
		ans=1;
		for(long long i=1;i<=n;++i)
		  ans=ans*i%M;
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		if(!mn||S.find('0')!=-1)
		{
			cout<<"0";
			return 0;
		}
		ans=1;
		for(long long i=1;i<=n;++i)
		  ans=ans*i%M;
		cout<<ans;
		return 0;
	}
	ans=0;
	dfs(1);
	cout<<ans;
	return 0;
}