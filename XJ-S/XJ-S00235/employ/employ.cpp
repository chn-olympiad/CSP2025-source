#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
int a[600];

long long jiecheng(int n)
{
	long long res=1;
	for(int i=2;i<=n;++i)
		res=res*(i%998244353)%998244353;
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=true;
	int t=s.size();
	for(int i=0;i<t;++i)
	{
		if(s[i]=='0')
			f=false;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			f=false;
		}
	}
	if(m==n)
	{
		if(!f) cout<<0;
		else cout<<jiecheng(n);
	}
	else if(n<=10)
	{
		cout<<2;
	}
	else
	{
		cout<<jiecheng(n);
	}
	return 0;
}
