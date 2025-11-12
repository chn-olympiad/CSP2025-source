#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,c=0,ss=0,l=1,cc=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')c++;
		else cc++;
	}
	if(m==n&&c!=n)
	{
		cout<<0;
		return 0;
	}
	if(c==n)
	{
		for(int i=1;i<=n-1;i++)
		{
			l=(l*i)%998244353;
		}
		cout<<l%998244353;
	}
	if(cc==n)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=c-1;i++)
	{
		l=(l*i)%998244353;
	}
	cout<<l;
 	return 0;
}