#include<bits/stdc++.h>
using namespace std;
long long n,m,ss[510],mod=998244353,r,c[510],ans=1,r2;
string s;
bool f;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	f=true;
	for(int i=0;i<s.size();i++)
	{
		ss[i+1]=s[i]-'0';
		if(s[i]=='1')
		{
			r++;
		}
		else
		{
			f=false;
		}
	}
	if(r<m)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			r2++;
		}
	}
	if(r2<m)
	{
		cout<<"0";
		return 0;
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
