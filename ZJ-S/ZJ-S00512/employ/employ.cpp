#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
const int mod=998244353;
int c[N];
bool q[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		q[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(q[i]==0||c[i]==0) 
			{
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	return 0;
}
