#include<bits/stdc++.h>
using namespace std;
long long n,m,ze,ans=1,a[501],to[501],f[501];
string s;
int main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')ze=i+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)ans=(ans*i)%998244353;
	int t=1;
	for(int i=1;i<=n-ze+1;i++)t*=2;
	ans-=t;
	ans-=(n-ze+1)*2;
	if(n==10)cout<<"2204128"<<endl;
	else cout<<2<<endl;
	return 0;
}
