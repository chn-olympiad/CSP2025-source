#include<bits/stdc++.h>
using namespace std;
char s[600];
bool f=1;
int n,m,a[600];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long p;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]!='1') f=0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans%998244353*i;
		}
		cout<<ans%998244353;
	}
	else cout<<p%998244353;
	return 0;
} 
