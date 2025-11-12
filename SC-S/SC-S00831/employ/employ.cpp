#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],flag=0,cnt;
int f[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	f[0]=1;
	for(int i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt--;
	}
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') flag=1;
	}
	if(!flag) cout<<f[cnt];
	return 0;
}
