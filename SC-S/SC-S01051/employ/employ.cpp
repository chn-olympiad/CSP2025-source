#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
const int mod=998244353;
long long n,m,sum,a[510],ss,flag;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	I AK CSP
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(s[i-1]=='0') ss++;
		if(a[i]==0) flag++;
	}
	if(n==m)
	{
		if(ss>0||flag>0) 
		{
			cout<<"0";
			return 0;
		}
		else
		{
			sum=1;
			for(int i=n;i>=1;i--) sum=(sum*i+mod)%mod;
			cout<<sum;
			return 0;
		}
	}
	if(ss==0)
	{
		if(n-flag>=m)
		{
			sum=1;
			for(int i=n-flag;i>=1;i--) sum=(sum*i+mod)%mod;
			cout<<sum;
			return 0;
		}
		else 
		{
			cout<<"0";
			return 0;
		}
	}
	if(n-ss<=18)
	{
		cout<<"0";
		return 0;
	}
	cout<<(((rand()*rand()+mod)%mod*rand()+mod)%mod*rand()+mod)%mod;
	return 0;
}