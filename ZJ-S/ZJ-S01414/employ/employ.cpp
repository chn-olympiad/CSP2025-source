#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],zzz,ss[501];
string s;
bool ts,t[11];
void dfs(int c,int sss)
{
	if(c>n)
	{
		if(sss>=m)
		  ++zzz;
		zzz%=998244353;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!t[i])
		{
			t[i]=true;
			if(ss[i]>=a[c]||s[c-1]=='0')
			  dfs(c+1,sss);else
			  dfs(c+1,sss+1);
			t[i]=false;
		}
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i)
	  cin>>a[i];
	ts=false;
	for(int i=0;i<s.size();++i)
		if(s[i]=='0')
		{
			ts=true;
			ss[i+1]=ss[i]+1;
		}else
			ss[i+1]=ss[i];
	    
	sort(a+1,a+1+n,cmp);
	if(!ts)
	{
		zzz=1;
		for(int i=n;i>=1;--i)
		{
//			if(a[i]==0)
//			  continue;
			zzz*=i;
			zzz%=998244353;
		}
		cout<<zzz;
		return 0;
	}
	if(n<=10)
	{
		dfs(1,0);
		cout<<zzz;
	}
}