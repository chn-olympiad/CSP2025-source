#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans=1,n,m,cnt,cnt1;
string s;
int a[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt1++;
	}
	for(int i=0;i<s.size();i++)
		if(s[i]=='1') cnt++;
	if(cnt==n)
	{
		for(int i=n-m+1;i<=n-cnt1;i++)
			ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	return 0;
}
