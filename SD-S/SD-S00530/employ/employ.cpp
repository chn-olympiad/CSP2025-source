#include<bits/stdc++.h>
using namespace std;
//#define ll long long
//#define endl '\n'
const int mod=998244353;
long long n,m,ans;
string s;
long long c[505];
long long p(int o)
{
	if(o==1)return 1;
	if(o==2)return 2;
	if(o==3)return 6;
	if(o==4)return 24;
	if(o==5)return 120;
	if(o==6)return 720;
	if(o==7)return 5040;
	if(o==8)return 40320;
	if(o==9)return 362880;
	if(o==10)return 3628800;
	if(o==11)return 39916800;
	if(o==12)return 479001600;
	if(o==13)return 6227020800;
	if(o==14)return 37178291200;
	return o*p(o-1);
}
long long C(long long n,long long m)
{
	if(n==0)return 1;
	if(n==m)return 1;
	if(m==1)return n%mod;
	if(n==1)return 1;
	return p(n)%mod/(p(n-m)%mod*p(m)%mod);
	return (C(n-1,m)%mod+C(n-1,m-1)%mod);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(long long i=m;i<=n;i++)
	{
		ans=ans%mod+C(n,i)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

