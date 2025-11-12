#include<bits/stdc++.h>
using namespace std;
int n,m,c[105];
char s[105];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='1')flag++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(flag<m)
	{
		cout<<"0";
		return 0;
	}
	if(flag==n)
	{
		long long ans=1;
		for(long long i=1;i<=n;i++)
		{
			ans*=i;
			ans%=(long long)998244353;
		}
		cout<<ans;
		return 0;
	}
	
}