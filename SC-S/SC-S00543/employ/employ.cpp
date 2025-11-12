#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;
long long ans=0;
int n,m,d[505],c[505];
string s;


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int f1=1;
	for(int i=0;i<s.length();i++)
	{
		d[i+1]=s[i]-'0';
		if(d[i+1]!=1)
			f1=0;
	}
	int sp=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]<=sp)
			sp++;
	}
	if(f1==1)
	{
		if(n-sp<m)
			cout<<0;
		else
		{
			ans=1;
			for(int i=n;i>=1;i--)
				ans=(ans*i)%mod;
			cout<<ans;
		}
		return 0;
	}
	else if(m==n)
	{
		cout<<0;
		return 0;
	}
	
	return 0;
}